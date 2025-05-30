#ifndef SONICTEAM__SOX__ERRORMSG
#define SONICTEAM__SOX__ERRORMSG


namespace Sonicteam{
	namespace ErrorMSG{



		extern wchar_t* SONICNEXT = L"SONIC THE HEDGEHOG";

		extern const wchar_t* ConfirmMSG[6] = {
			L"確認",
			L"Confirm",
			L"Confirmer",
			L"Bestätigen",
			L"Conferma",
			L"Confirmar",
		};

		extern const wchar_t* SignInStatusChangedMSG[6] = {
			L"サインインの状態が変更されました。\nゲームを続けることができません。\nタイトルに戻ります。",
			L"Your sign-in status has changed.\nThe game cannot be continued.\nReturning to the Title Screen.",
			L"Votre statut de connexion a changé.\nVous ne pouvez pas continuer à jouer.\nRetour à l'écran du titre.",
			L"Dein Anmeldestatus hat sich geändert.\nDas Spiel kann nicht fortgesetzt werden.\nZurück zum Titelbildschirm.",
			L"Il tuo stato di connessione è stato modificato.\nLa partita non può essere continuata.\nRitorno alla schermata del titolo in corso.",
			L"El estado de la sesión ha cambiado.\nLa partida no puede continuar.\nVolviendo a la pantalla de inicio."
		};



	}
}

#endif