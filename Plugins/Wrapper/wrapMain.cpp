//---------------------------------------------------------------------------

#include <windows.h>
#include "server.h"
#include "..\VMProtectSDK.h"

char dirPlug[1024];
HANDLE *threads;
Servidor *servidor;

bool GravarPorta(DWORD porta) {
	VMProtectBegin("grvVersao");
	HKEY hKey = 0;
	char buf[255] = {0};
	DWORD dwType = 0;
	DWORD dwBufSize = sizeof(buf);
	const char* subkey = "SOFTWARE\\SoftX";
	if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, subkey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS | KEY_WOW64_32KEY, NULL, &hKey, &dwType) == ERROR_SUCCESS) {
		//dwType = REG_SZ;
		RegSetValueEx(hKey, "Version", 0, REG_DWORD, (const unsigned char*)&porta, sizeof(DWORD));
		RegCloseKey(hKey);
		return true;
	}
	return false;
	VMProtectEnd();
}

void __stdcall PASCAL OnClientDisconnect(ContextoCliente *contexto) {
}

void __stdcall PASCAL OnClientConnect(ContextoCliente *contexto) {
	servidor->enviar(contexto->socket, TP_MENSAGEM, (char*)&dirPlug[0], strlen(&dirPlug[0]));
}

void __stdcall processar(ContextoCliente *contexto, PACOTE *pacote) {
}

bool conectarServidor() {
	servidor = new Servidor((PROC)processar);
	servidor->onClientDisconnect = (PROC)OnClientDisconnect;
	servidor->onClientConnect = (PROC)OnClientConnect;

	//
	// Procura uma porta livre para conex�o do servidor
	for (int i = 3131, j = 0; i < 30999; i++) {
		if (servidor->conectar(i)) {
			break;
		}
		// Falha ao conectar na porta
		debugar("Erro 9222. N� %d", i);
		if (i >= 30999) {
			return false;
		}
	}
	// HideDll(instanceDLL);
	GravarPorta(servidor->getPorta()*1354);
	return true;
} 

bool inicializado = false;

extern "C" __stdcall __declspec(dllexport) void WINAPI _s0(char* valor) {
	strcat(&dirPlug[0],valor);
	conectarServidor();
	debugar("wmx: %s", &dirPlug[0]);
}

extern "C" __stdcall __declspec(dllexport) void WINAPI _s1(int valor, char* dir) {
	//strcat(&dirPlug[0],valor);
	//conectarServidor();
	MapRemoteModule(valor, dir);
}

#pragma argsused
WSADATA dataWSA;
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved) {
	switch (reason) {
	case DLL_PROCESS_ATTACH: {
			DisableThreadLibraryCalls(hinst);
			__try{
				WSAStartup(0x101,&dataWSA);
			}__except(1){
			}

			memset(&dirPlug[0], 0, 1024);

			return 1;
		} break;
	case DLL_PROCESS_DETACH: {
			// debugar("descarregando...");
			//debugar("going away...");
		} break;

	default:
		break;
	}
	return true;
}
//---------------------------------------------------------------------------
