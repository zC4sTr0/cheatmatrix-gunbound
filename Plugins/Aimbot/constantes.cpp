//---------------------------------------------------------------------------


#pragma hdrstop

#include "constantes.h"
#include "..\VMProtectSDK.h"

//---------------------------------------------------------------------------
AnsiString getString(int id){
	return constante(id);
}

AnsiString constante(int id){
VMProtectBegin("cst");
	BYTE linguagem = *idioma;
	if(linguagem == PT_BR){
		switch(id){
			case 1: return "Geral";
			case 2: return "Op��es";
			case 3: return "Mobiles";
			case 4: return "Ajuda";
			case 5: return "Vers�o:";
			case 6: return "Autor:";
			case 7: return "Modo de Mira";
			case 8: return "Mais Pr�ximo";
			case 9: return "Mais Longe";
			case 10: return "Slice";
			case 11: return "Mouse";
			case 12: return "Aleat�rio";
			case 13: return "Personalizado";
			case 14: return "Linha";
			case 15: return "Configura��es";
			case 16: return "Atalhos";
			case 17: return "Cor da Mira";
			case 18: return "Cor da Mira 2 (SS e TC)";
			case 19: return "Cor da Marca de Espelho";
			case 20: return "Cor da Marca de Tornado";
			case 21: return "Amostragem do Status";
			case 22: return "Espessura da Linha";
			case 23: return "Modo GDI";
			case 24: return "Mirar em amigos";
			case 25: return "Salvar configs";
			case 26: return "Carregar configs";
			case 27: return "Restaurar configs";
			case 28: return "Ligar/Desligar";
			case 29: return "Status do Aim";
			case 30: return "Pr�ximo Mobile";
			case 31: return "Mobile Anterior";
			case 32: return "Pr�ximo Alvo";
			case 33: return "Alvo Anterior";
			case 34: return "Pr�ximo modo de mira";
			case 35: return "Modo de mira anterior";
			case 36: return "Detectar Mobile";
			case 37: return "Backshot";
			case 38: return "Linha vertical no mouse";
			case 39: return "Marcar tornado/espelho";
			case 40: return "Remover tornado/espelho";
			case 41: return "Limpar tornados/espelhos";
			case 42: return "Alternar tornado/espelho";
			case 43: return "Usar auto-shot";
			case 44: return "Tirar Screenshot";
			case 45: return "Mover Menu";
			case 46: return "Tiro composto de Big Foot";
			case 47: return "Tiro composto de Mage";
			case 48: return "Tiro composto de Trico";
			case 49: return "Tiro composto de Turtle";
			case 50: return "Tiro composto de Grub";
			case 51: return "Tiro composto de Kasildon";
			case 52: return "Tiro composto de Maya";
			case 53: return "Tiro composto de Drag�o";
			case 54: return "Tiro composto de Raon";
			case 55: return "Tiro composto de Frank";
			case 56: return "Invers�o de Nak";
			case 57: return "Raio(s) de A.Sate";
			case 58: return "Marcar SS";
			case 59: return "Descri��o";
			case 60: return "Dicas";
			case 61: return "          D� uma no��o de for�a/distancia para um lan�amento de proj�til, com a��o de for�as externas, para GB. � um aimbot longo alcance, ou seja, pode mirar de qualquer parte para qualquer outra parte do mapa.";
			case 62: return "     -=> Se estiver no modo MOUSE, pressione CTRL para parar a mira no local atual, para que possa atirar com o mouse ou mov�-lo sem alterar a posi��o da mira e quantidade de for�a indicada pelo aim.";
			case 63: return "Atalho";
			case 64: return "Selecionar alvo";
			case 65: return "desconhecido";
			case 66: return "Este atalho j� est� em uso!";
			case 67: return "Aten��o";
			case 68: return "Voc� deve reiniciar o CMX para que as modifica��es tenham efeito.";
		}
	} else {
    	switch(id){
			case 1: return "General";
			case 2: return "Options";
			case 3: return "Mobiles";
			case 4: return "Help";
			case 5: return "Version:";
			case 6: return "Author:";
			case 7: return "Aim Mode";
			case 8: return "Shorter";
			case 9: return "Further";
			case 10: return "Slice";
			case 11: return "Mouse";
			case 12: return "Random";
			case 13: return "Custom";
			case 14: return "Line";
			case 15: return "Configs";
			case 16: return "Hotkeys";
			case 17: return "Line color";
			case 18: return "Line color 2 (SS and CS)";
			case 19: return "Mirror mark color";
			case 20: return "Tornado mark color";
			case 21: return "Status Window Time";
			case 22: return "Line Weight";
			case 23: return "GDI mode";
			case 24: return "Aim friends";
			case 25: return "Save configs";
			case 26: return "Load configs";
			case 27: return "Restore configs";
			case 28: return "Turn On/Off";
			case 29: return "Aim Status";
			case 30: return "Next Mobile";
			case 31: return "Previous Mobile";
			case 32: return "Next Target";
			case 33: return "Previous Target";
			case 34: return "Next aim mode";
			case 35: return "Previous aim mode";
			case 36: return "Detect Mobile";
			case 37: return "Backshot";
			case 38: return "Vertical Line";
			case 39: return "Mark tornado/mirror";
			case 40: return "Remove tornado/mirror";
			case 41: return "Clear tornados/mirrors";
			case 42: return "Choose tornado/mirror";
			case 43: return "Use auto shot";
			case 44: return "Take a Screenshot";
			case 45: return "Move Menu";
			case 46: return "Composite Shot of Big Foot";
			case 47: return "Composite Shot of Mage";
			case 48: return "Composite Shot of Trico";
			case 49: return "Composite Shot of Turtle";
			case 50: return "Composite Shot of Grub";
			case 51: return "Composite Shot of Kasildon";
			case 52: return "Composite Shot of Maya";
			case 53: return "Composite Shot of Drag�o";
			case 54: return "Composite Shot of Raon";
			case 55: return "Composite Shot of Frank";
			case 56: return "Nak inversion";
			case 57: return "A.Sate bolts";
			case 58: return "SS Mark";
			case 59: return "Description";
			case 60: return "Tips";
			case 61: return "          Gives a notion of force/distance to launch a projectile, with the action of external forces, to GB. It is a long-range aimbot, that can target any part of the map.";
			case 62: return "     -=> If you are in MOUSE mode, press CTRL to stop aiming at the current location, so you can shoot with the mouse or move it without changing the position of the target and amount of force indicated by the aim.";
			case 63: return "Hotkey";
			case 64: return "Select Target";
			case 65: return "unknown";
			case 66: return "This shortcut is already in use!";
			case 67: return "Warning";
			case 68: return "You must restart the CMX for the changes to take effect.";
		}
	}
VMProtectEnd();
}

#pragma package(smart_init)
