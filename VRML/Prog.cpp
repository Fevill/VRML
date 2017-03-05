#include <windows.h>
#include "resource.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int nb_objet = 0;
bool choix_texture;

bool texture=false;
int nb_objetPhysique=0;
HWND hwndcombo, hwndcombo2, hwndcombo3, hwndcombo4;

double x,y,z,t,theta;

TCHAR text0[]=TEXT("<aucune>");
TCHAR text1[]=TEXT("dalles.jpg");
TCHAR text2[]=TEXT("gravier.jpg");
TCHAR text3[]=TEXT("herbe.jpg");
TCHAR text4[]=TEXT("metal_rouil.jpg");
TCHAR text5[]=TEXT("mi-neige.jpg");
TCHAR text6[]=TEXT("mur.jpg");
TCHAR text7[]=TEXT("papier.jpg");
TCHAR text8[]=TEXT("paves.jpg");
TCHAR text9[]=TEXT("quadrillage.jpg");
TCHAR text10[]=TEXT("tole_rouil.jpg");
TCHAR text11[]=TEXT("eau.jpg");
TCHAR text12[]=TEXT("WRLPOOL.mpg");
CHAR listObjet[1000][250];
int nb_pan = 0, nb_sph = 0, nb_cyl = 0;
int nb_s = 0;

/*Texte family*/
TCHAR family_text1[] = TEXT("SERIF");

/*Texte Style*/
TCHAR style_text1[] = TEXT("BOLD");



char urll[30], url2[30], url3[30], url4[30];


float mat[12];



FILE *fich;


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

TCHAR szAppName[] = TEXT ("prog") ;




int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     HWND     hwnd ;
     MSG      msg ;
     WNDCLASS wndclass ;
     
     wndclass.style         = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);
     wndclass.lpszClassName = szAppName ;

     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("Ce programme fonctionne exclusivement sous Windows NT!"),
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName, TEXT ("Interface VRML"),
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;

}





LRESULT CALLBACK matiere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
TCHAR vIDC_ambientIntensity[10]=TEXT("0.2"),vIDC_DIFFX[10]=TEXT("0.8"),vIDC_DIFFY[10]=TEXT("0.8"),vIDC_DIFFZ[10]=TEXT("0.8"),
		vIDC_EMX[10]=TEXT("0"),vIDC_EMY[10]=TEXT("0"),vIDC_EMZ[10]=TEXT("0"),vIDC_BRIL[10]=TEXT("0.2"),
		vIDC_SPECX[10]=TEXT("0"),vIDC_SPECY[10]=TEXT("0"),vIDC_SPECZ[10]=TEXT("0"),vIDC_TRANSP[10]=TEXT("0");
	
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText(hwnd, IDC_ambientIntensity,vIDC_ambientIntensity);

			SetDlgItemText(hwnd, IDC_DIFFX,vIDC_DIFFX);
			SetDlgItemText(hwnd, IDC_DIFFY,vIDC_DIFFY);
			SetDlgItemText(hwnd, IDC_DIFFZ,vIDC_DIFFZ);
			SetDlgItemText(hwnd, IDC_EMX,vIDC_EMX);
			SetDlgItemText(hwnd, IDC_EMY,vIDC_EMY);
			SetDlgItemText(hwnd, IDC_EMZ,vIDC_EMZ);
			SetDlgItemText(hwnd, IDC_BRIL,vIDC_BRIL);
			SetDlgItemText(hwnd, IDC_SPECX,vIDC_SPECX);
			SetDlgItemText(hwnd, IDC_SPECY,vIDC_SPECY);
			SetDlgItemText(hwnd, IDC_SPECZ,vIDC_SPECZ);
			SetDlgItemText(hwnd, IDC_TRANSP,vIDC_TRANSP);

		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_ambientIntensity,vIDC_ambientIntensity,10);
					GetDlgItemText(hwnd, IDC_DIFFX,vIDC_DIFFX,10);
					GetDlgItemText(hwnd, IDC_DIFFY,vIDC_DIFFY,10);
					GetDlgItemText(hwnd, IDC_DIFFZ,vIDC_DIFFZ,10);
					GetDlgItemText(hwnd, IDC_EMX,vIDC_EMX,10);
					GetDlgItemText(hwnd, IDC_EMY,vIDC_EMY,10);
					GetDlgItemText(hwnd, IDC_EMZ,vIDC_EMZ,10);
					GetDlgItemText(hwnd, IDC_BRIL,vIDC_BRIL,10);
					GetDlgItemText(hwnd, IDC_SPECX,vIDC_SPECX,10);
					GetDlgItemText(hwnd, IDC_SPECY,vIDC_SPECY,10);
					GetDlgItemText(hwnd, IDC_SPECZ,vIDC_SPECZ,10);
					GetDlgItemText(hwnd, IDC_TRANSP,vIDC_TRANSP,10);

                   	mat[0] = _wtof(vIDC_ambientIntensity);
					mat[1] = _wtof(vIDC_DIFFX);
					mat[2] = _wtof(vIDC_DIFFY);
					mat[3] = _wtof(vIDC_DIFFZ);
					mat[4] = _wtof(vIDC_EMX);
					mat[5] = _wtof(vIDC_EMY);
					mat[6] = _wtof(vIDC_EMZ);
					mat[7] = _wtof(vIDC_BRIL);
					mat[8] = _wtof(vIDC_SPECX);
					mat[9] = _wtof(vIDC_SPECY);
					mat[10] = _wtof(vIDC_SPECZ);
					mat[11] = _wtof(vIDC_TRANSP);
						
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

/********************************************************************************************************************/
/*****************                                     GEOMETRI                                   *******************/
/********************************************************************************************************************/
LRESULT CALLBACK cylindre(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0"),vIDC_Hauteur[10]=TEXT("2.0");
	char nom[10]="objet";
	char fullnom[20];
	int i = 0,j=0;
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_Hauteur,vIDC_Hauteur);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_HAUT, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					GetDlgItemText(hwnd,IDC_Hauteur,vIDC_Hauteur,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
                    if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE; //texture fixe
					else choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					sprintf_s(fullnom, "%s%d", nom, nb_objet);
					++nb_objetPhysique;
					while (fullnom[i] != '\0') {
						listObjet[nb_objetPhysique][i] = fullnom[i];
						i++;
					}
					listObjet[nb_objetPhysique][i] = '\0';
					
                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
                      if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					    }
				
					      }
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Cylinder{\n");
					fwprintf(fich,L"radius %s \n height %s\n",vIDC_Rayon, vIDC_Hauteur);
					if(IsDlgButtonChecked(hwnd, IDC_HAUT) == BST_UNCHECKED) fprintf(fich, "top FALSE\n");
					if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_UNCHECKED) fprintf(fich, "bottom FALSE\n");
					if(IsDlgButtonChecked(hwnd, IDC_COTE) == BST_UNCHECKED) fprintf(fich, "side FALSE\n");
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK sphere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10] = TEXT("0"), vIDC_Dy[10] = TEXT("0"), vIDC_Dz[10] = TEXT("0"), vIDC_AxeX[10] = TEXT("1"), vIDC_AxeY[10] = TEXT("0"), vIDC_AxeZ[10] = TEXT("0"),
		vIDC_Angle[10] = TEXT("0"), vIDC_Rayon[10] = TEXT("1.0");
	char nom[10] = "objet";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_Dx, vIDC_Dx);
		SetDlgItemText(hwnd, IDC_Dy, vIDC_Dy);
		SetDlgItemText(hwnd, IDC_Dz, vIDC_Dz);
		SetDlgItemText(hwnd, IDC_AxeX, vIDC_AxeX);
		SetDlgItemText(hwnd, IDC_AxeY, vIDC_AxeY);
		SetDlgItemText(hwnd, IDC_AxeZ, vIDC_AxeZ);
		SetDlgItemText(hwnd, IDC_Angle, vIDC_Angle);
		SetDlgItemText(hwnd, IDC_Rayon, vIDC_Rayon);
		hwndcombo = GetDlgItem(hwnd, IDC_COMBO_FIXE);
		hwndcombo2 = GetDlgItem(hwnd, IDC_COMBO_ANIME);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text1);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text2);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text3);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text4);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text5);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text6);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text7);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text8);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text9);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text10);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text11);
		SendMessage(hwndcombo, CB_SETCURSEL, 0, 0);
		SendMessage(hwndcombo2, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo2, CB_ADDSTRING, 0, (LPARAM)text12);
		SendMessage(hwndcombo2, CB_SETCURSEL, 0, 0);

		CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam)  {

		case IDOK:
			GetDlgItemText(hwnd, IDC_Dx, vIDC_Dx, 10);
			GetDlgItemText(hwnd, IDC_Dy, vIDC_Dy, 10);
			GetDlgItemText(hwnd, IDC_Dz, vIDC_Dz, 10);
			GetDlgItemText(hwnd, IDC_AxeX, vIDC_AxeX, 10);
			GetDlgItemText(hwnd, IDC_AxeY, vIDC_AxeY, 10);
			GetDlgItemText(hwnd, IDC_AxeZ, vIDC_AxeZ, 10);
			GetDlgItemText(hwnd, IDC_Angle, vIDC_Angle, 10);
			GetDlgItemText(hwnd, IDC_Rayon, vIDC_Rayon, 10);
			SendDlgItemMessage(hwnd, IDC_COMBO_FIXE, WM_GETTEXT, sizeof(urll), (LPARAM)urll);
			SendDlgItemMessage(hwnd, IDC_COMBO_ANIME, WM_GETTEXT, sizeof(url2), (LPARAM)url2);


			if (IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE; //texture fixe
			else choix_texture = FALSE; //texture animée

			++nb_objet;
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "DEF %s%d Transform {\n", nom, nb_objet);
			fwprintf(fich, L"translation %s %s %s\n", vIDC_Dx, vIDC_Dy, vIDC_Dz);
			fwprintf(fich, L"rotation %s %s %s %s\n", vIDC_AxeX, vIDC_AxeY, vIDC_AxeZ, vIDC_Angle);
			fwprintf(fich, L"children Shape {\n");
			fprintf(fich, "appearance Appearance {\n");

			if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
			{
				fprintf(fich, "material Material {\n");
				fprintf(fich, "ambientIntensity %g \n", mat[0]);
				fprintf(fich, "diffuseColor %g %g %g \n", mat[1], mat[2], mat[3]);
				fprintf(fich, "emissiveColor %g %g %g \n", mat[4], mat[5], mat[6]);
				fprintf(fich, "shininess %g \n", mat[7]);
				fprintf(fich, "specularColor %g %g %g \n", mat[8], mat[9], mat[10]);
				fprintf(fich, "transparency %g \n", mat[11]);
				fprintf(fich, "}\n");
			}
			else {
				if (choix_texture)
				{
					if (strcmp(urll, "<aucune>") != 0)

						fwprintf(fich, L"texture ImageTexture { url \".\\textures\\%s\" \n }\n", urll);
				}
				else
				{
					if (strcmp(url2, "<aucune>") != 0)

						fwprintf(fich, L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n", url2);
				}

			}
			fprintf(fich, "}\n");
			fprintf(fich, "geometry Sphere{\n");
			fwprintf(fich, L"radius %s \n", vIDC_Rayon);
			fprintf(fich, "}\n");
			fprintf(fich, "}\n");
			fprintf(fich, "},\n");
			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDC_OPTIONS:
			DialogBox(NULL, MAKEINTRESOURCE(IDD_MATIERE), hwnd, (DLGPROC)matiere);
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

LRESULT CALLBACK boite(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10] = TEXT("0"), vIDC_Dy[10] = TEXT("0"), vIDC_Dz[10] = TEXT("0"), vIDC_AxeX[10] = TEXT("1"), vIDC_AxeY[10] = TEXT("0"), vIDC_AxeZ[10] = TEXT("0"),
		vIDC_Angle[10] = TEXT("0"), vIDC_Size_X[10] = TEXT("1.0"), vIDC_Size_Y[10] = TEXT("1.0"), vIDC_Size_Z[10] = TEXT("1.0");
	char nom[10] = "objet";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_Dx, vIDC_Dx);
		SetDlgItemText(hwnd, IDC_Dy, vIDC_Dy);
		SetDlgItemText(hwnd, IDC_Dz, vIDC_Dz);
		SetDlgItemText(hwnd, IDC_AxeX, vIDC_AxeX);
		SetDlgItemText(hwnd, IDC_AxeY, vIDC_AxeY);
		SetDlgItemText(hwnd, IDC_AxeZ, vIDC_AxeZ);
		SetDlgItemText(hwnd, IDC_Angle, vIDC_Angle);
		SetDlgItemText(hwnd, IDC_SizeX, vIDC_Size_X);
		SetDlgItemText(hwnd, IDC_SizeY, vIDC_Size_Y);
		SetDlgItemText(hwnd, IDC_SizeZ, vIDC_Size_Z);
		hwndcombo = GetDlgItem(hwnd, IDC_COMBO_FIXE);
		hwndcombo2 = GetDlgItem(hwnd, IDC_COMBO_ANIME);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text1);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text2);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text3);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text4);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text5);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text6);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text7);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text8);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text9);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text10);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text11);
		SendMessage(hwndcombo, CB_SETCURSEL, 0, 0);
		SendMessage(hwndcombo2, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo2, CB_ADDSTRING, 0, (LPARAM)text12);
		SendMessage(hwndcombo2, CB_SETCURSEL, 0, 0);

		CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam)  {

		case IDOK:
			GetDlgItemText(hwnd, IDC_Dx, vIDC_Dx, 10);
			GetDlgItemText(hwnd, IDC_Dy, vIDC_Dy, 10);
			GetDlgItemText(hwnd, IDC_Dz, vIDC_Dz, 10);
			GetDlgItemText(hwnd, IDC_AxeX, vIDC_AxeX, 10);
			GetDlgItemText(hwnd, IDC_AxeY, vIDC_AxeY, 10);
			GetDlgItemText(hwnd, IDC_AxeZ, vIDC_AxeZ, 10);
			GetDlgItemText(hwnd, IDC_Angle, vIDC_Angle, 10);
			GetDlgItemText(hwnd, IDC_SizeX, vIDC_Size_X, 10);
			GetDlgItemText(hwnd, IDC_SizeY, vIDC_Size_Y, 10);
			GetDlgItemText(hwnd, IDC_SizeZ, vIDC_Size_Z, 10);
			SendDlgItemMessage(hwnd, IDC_COMBO_FIXE, WM_GETTEXT, sizeof(urll), (LPARAM)urll);
			SendDlgItemMessage(hwnd, IDC_COMBO_ANIME, WM_GETTEXT, sizeof(url2), (LPARAM)url2);


			if (IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE; //texture fixe
			else choix_texture = FALSE; //texture animée

			++nb_objet;
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "DEF %s%d Transform {\n", nom, nb_objet);
			fwprintf(fich, L"translation %s %s %s\n", vIDC_Dx, vIDC_Dy, vIDC_Dz);
			fwprintf(fich, L"rotation %s %s %s %s\n", vIDC_AxeX, vIDC_AxeY, vIDC_AxeZ, vIDC_Angle);
			fwprintf(fich, L"children Shape {\n");
			fprintf(fich, "appearance Appearance {\n");

			if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
			{
				fprintf(fich, "material Material {\n");
				fprintf(fich, "ambientIntensity %g \n", mat[0]);
				fprintf(fich, "diffuseColor %g %g %g \n", mat[1], mat[2], mat[3]);
				fprintf(fich, "emissiveColor %g %g %g \n", mat[4], mat[5], mat[6]);
				fprintf(fich, "shininess %g \n", mat[7]);
				fprintf(fich, "specularColor %g %g %g \n", mat[8], mat[9], mat[10]);
				fprintf(fich, "transparency %g \n", mat[11]);
				fprintf(fich, "}\n");
			}
			else {
				if (choix_texture)
				{
					if (strcmp(urll, "<aucune>") != 0)

						fwprintf(fich, L"texture ImageTexture { url \".\\textures\\%s\" \n }\n", urll);
				}
				else
				{
					if (strcmp(url2, "<aucune>") != 0)

						fwprintf(fich, L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n", url2);
				}

			}
			fprintf(fich, "}\n");
			fprintf(fich, "geometry Box{\n");
			fwprintf(fich, L"size %s %s %s \n", vIDC_Size_X, vIDC_Size_Y, vIDC_Size_Z);
			fprintf(fich, "}\n");
			fprintf(fich, "}\n");
			fprintf(fich, "},\n");
			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDC_OPTIONS:
			DialogBox(NULL, MAKEINTRESOURCE(IDD_MATIERE), hwnd, (DLGPROC)matiere);
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

LRESULT CALLBACK cone(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10] = TEXT("0"), vIDC_Dy[10] = TEXT("0"), vIDC_Dz[10] = TEXT("0"), vIDC_AxeX[10] = TEXT("1"), vIDC_AxeY[10] = TEXT("0"), vIDC_AxeZ[10] = TEXT("0"),
		vIDC_Angle[10] = TEXT("0"), vIDC_Rayon[10] = TEXT("1.0"), vIDC_Hauteur[10] = TEXT("2.0");
	char nom[10] = "objet";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_Dx, vIDC_Dx);
		SetDlgItemText(hwnd, IDC_Dy, vIDC_Dy);
		SetDlgItemText(hwnd, IDC_Dz, vIDC_Dz);
		SetDlgItemText(hwnd, IDC_AxeX, vIDC_AxeX);
		SetDlgItemText(hwnd, IDC_AxeY, vIDC_AxeY);
		SetDlgItemText(hwnd, IDC_AxeZ, vIDC_AxeZ);
		SetDlgItemText(hwnd, IDC_Angle, vIDC_Angle);
		SetDlgItemText(hwnd, IDC_Rayon, vIDC_Rayon);
		SetDlgItemText(hwnd, IDC_Hauteur, vIDC_Hauteur);
		hwndcombo = GetDlgItem(hwnd, IDC_COMBO_FIXE);
		hwndcombo2 = GetDlgItem(hwnd, IDC_COMBO_ANIME);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text1);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text2);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text3);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text4);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text5);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text6);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text7);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text8);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text9);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text10);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text11);
		SendMessage(hwndcombo, CB_SETCURSEL, 0, 0);
		SendMessage(hwndcombo2, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo2, CB_ADDSTRING, 0, (LPARAM)text12);
		SendMessage(hwndcombo2, CB_SETCURSEL, 0, 0);

		CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
		CheckDlgButton(hwnd, IDC_HAUT, BST_CHECKED);
		CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
		CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam)  {

		case IDOK:
			GetDlgItemText(hwnd, IDC_Dx, vIDC_Dx, 10);
			GetDlgItemText(hwnd, IDC_Dy, vIDC_Dy, 10);
			GetDlgItemText(hwnd, IDC_Dz, vIDC_Dz, 10);
			GetDlgItemText(hwnd, IDC_AxeX, vIDC_AxeX, 10);
			GetDlgItemText(hwnd, IDC_AxeY, vIDC_AxeY, 10);
			GetDlgItemText(hwnd, IDC_AxeZ, vIDC_AxeZ, 10);
			GetDlgItemText(hwnd, IDC_Angle, vIDC_Angle, 10);
			GetDlgItemText(hwnd, IDC_Rayon, vIDC_Rayon, 10);
			GetDlgItemText(hwnd, IDC_Hauteur, vIDC_Hauteur, 10);
			SendDlgItemMessage(hwnd, IDC_COMBO_FIXE, WM_GETTEXT, sizeof(urll), (LPARAM)urll);
			SendDlgItemMessage(hwnd, IDC_COMBO_ANIME, WM_GETTEXT, sizeof(url2), (LPARAM)url2);


			if (IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE; //texture fixe
			else choix_texture = FALSE; //texture animée

			++nb_objet;
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "DEF %s%d Transform {\n", nom, nb_objet);
			fwprintf(fich, L"translation %s %s %s\n", vIDC_Dx, vIDC_Dy, vIDC_Dz);
			fwprintf(fich, L"rotation %s %s %s %s\n", vIDC_AxeX, vIDC_AxeY, vIDC_AxeZ, vIDC_Angle);
			fwprintf(fich, L"children Shape {\n");
			fprintf(fich, "appearance Appearance {\n");

			if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
			{
				fprintf(fich, "material Material {\n");
				fprintf(fich, "ambientIntensity %g \n", mat[0]);
				fprintf(fich, "diffuseColor %g %g %g \n", mat[1], mat[2], mat[3]);
				fprintf(fich, "emissiveColor %g %g %g \n", mat[4], mat[5], mat[6]);
				fprintf(fich, "shininess %g \n", mat[7]);
				fprintf(fich, "specularColor %g %g %g \n", mat[8], mat[9], mat[10]);
				fprintf(fich, "transparency %g \n", mat[11]);
				fprintf(fich, "}\n");
			}
			else {
				if (choix_texture)
				{
					if (strcmp(urll, "<aucune>") != 0)

						fwprintf(fich, L"texture ImageTexture { url \".\\textures\\%s\" \n }\n", urll);
				}
				else
				{
					if (strcmp(url2, "<aucune>") != 0)

						fwprintf(fich, L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n", url2);
				}

			}
			fprintf(fich, "}\n");
			fprintf(fich, "geometry Cone{\n");
			fwprintf(fich, L"bottomRadius %s \n height %s\n", vIDC_Rayon, vIDC_Hauteur);
			if (IsDlgButtonChecked(hwnd, IDC_COTE) == BST_UNCHECKED) fprintf(fich, "side TRUE\n");
			if (IsDlgButtonChecked(hwnd, IDC_BAS) == BST_UNCHECKED) fprintf(fich, "bottom TRUE\n");
			fprintf(fich, "}\n");
			fprintf(fich, "}\n");
			fprintf(fich, "},\n");
			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDC_OPTIONS:
			DialogBox(NULL, MAKEINTRESOURCE(IDD_MATIERE), hwnd, (DLGPROC)matiere);
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

LRESULT CALLBACK texte(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10] = TEXT("0"), vIDC_Dy[10] = TEXT("0"), vIDC_Dz[10] = TEXT("0"), vIDC_AxeX[10] = TEXT("1"), vIDC_AxeY[10] = TEXT("0"), vIDC_AxeZ[10] = TEXT("0"),
		vIDC_Angle[10] = TEXT("0"), vIDC_Test1[1000] = TEXT("Bonjour Tout le monde"), vIDC_Size[20] = TEXT("1.0");
	char nom[10] = "objet";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_Dx, vIDC_Dx);
		SetDlgItemText(hwnd, IDC_Dy, vIDC_Dy);
		SetDlgItemText(hwnd, IDC_Dz, vIDC_Dz);
		SetDlgItemText(hwnd, IDC_AxeX, vIDC_AxeX);
		SetDlgItemText(hwnd, IDC_AxeY, vIDC_AxeY);
		SetDlgItemText(hwnd, IDC_AxeZ, vIDC_AxeZ);
		SetDlgItemText(hwnd, IDC_Angle, vIDC_Angle);
		SetDlgItemText(hwnd, IDC_Text_1, vIDC_Test1);
		SetDlgItemText(hwnd, IDC_Size, vIDC_Size);
		hwndcombo = GetDlgItem(hwnd, IDC_COMBO_FIXE);
		hwndcombo2 = GetDlgItem(hwnd, IDC_COMBO_ANIME);
		hwndcombo3 = GetDlgItem(hwnd, IDC_COMBO_FAMILY);
		hwndcombo4 = GetDlgItem(hwnd, IDC_COMBO_STYLE);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text1);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text2);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text3);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text4);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text5);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text6);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text7);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text8);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text9);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text10);
		SendMessage(hwndcombo, CB_ADDSTRING, 0, (LPARAM)text11);
		SendMessage(hwndcombo, CB_SETCURSEL, 0, 0);
		SendMessage(hwndcombo2, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo2, CB_ADDSTRING, 0, (LPARAM)text12);
		SendMessage(hwndcombo2, CB_SETCURSEL, 0, 0);
		SendMessage(hwndcombo3, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo3, CB_ADDSTRING, 0, (LPARAM)family_text1);
		SendMessage(hwndcombo3, CB_SETCURSEL, 0, 0);
		SendMessage(hwndcombo4, CB_ADDSTRING, 0, (LPARAM)text0);
		SendMessage(hwndcombo4, CB_ADDSTRING, 0, (LPARAM)style_text1);
		SendMessage(hwndcombo4, CB_SETCURSEL, 0, 0);

		CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam)  {

		case IDOK:
			GetDlgItemText(hwnd, IDC_Dx, vIDC_Dx, 10);
			GetDlgItemText(hwnd, IDC_Dy, vIDC_Dy, 10);
			GetDlgItemText(hwnd, IDC_Dz, vIDC_Dz, 10);
			GetDlgItemText(hwnd, IDC_AxeX, vIDC_AxeX, 10);
			GetDlgItemText(hwnd, IDC_AxeY, vIDC_AxeY, 10);
			GetDlgItemText(hwnd, IDC_AxeZ, vIDC_AxeZ, 10);
			GetDlgItemText(hwnd, IDC_Angle, vIDC_Angle, 10);
			GetDlgItemText(hwnd, IDC_Text_1, vIDC_Test1, 1000);
			GetDlgItemText(hwnd, IDC_Size, vIDC_Size, 20);
			SendDlgItemMessage(hwnd, IDC_COMBO_FIXE, WM_GETTEXT, sizeof(urll), (LPARAM)urll);
			SendDlgItemMessage(hwnd, IDC_COMBO_ANIME, WM_GETTEXT, sizeof(url2), (LPARAM)url2);
			SendDlgItemMessage(hwnd, IDC_COMBO_FAMILY, WM_GETTEXT, sizeof(url3), (LPARAM)url3);
			SendDlgItemMessage(hwnd, IDC_COMBO_STYLE, WM_GETTEXT, sizeof(url4), (LPARAM)url4);


			if (IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE; //texture fixe
			else choix_texture = FALSE; //texture animée

			++nb_objet;
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "DEF %s%d Transform {\n", nom, nb_objet);
			fwprintf(fich, L"translation %s %s %s\n", vIDC_Dx, vIDC_Dy, vIDC_Dz);
			fwprintf(fich, L"rotation %s %s %s %s\n", vIDC_AxeX, vIDC_AxeY, vIDC_AxeZ, vIDC_Angle);
			fwprintf(fich, L"children Shape {\n");
			fprintf(fich, "appearance Appearance {\n");

			if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
			{
				fprintf(fich, "material Material {\n");
				fprintf(fich, "ambientIntensity %g \n", mat[0]);
				fprintf(fich, "diffuseColor %g %g %g \n", mat[1], mat[2], mat[3]);
				fprintf(fich, "emissiveColor %g %g %g \n", mat[4], mat[5], mat[6]);
				fprintf(fich, "shininess %g \n", mat[7]);
				fprintf(fich, "specularColor %g %g %g \n", mat[8], mat[9], mat[10]);
				fprintf(fich, "transparency %g \n", mat[11]);
				fprintf(fich, "}\n");
			}
			else {
				if (choix_texture)
				{
					if (strcmp(urll, "<aucune>") != 0)

						fwprintf(fich, L"texture ImageTexture { url \".\\textures\\%s\" \n }\n", urll);
				}
				else
				{
					if (strcmp(url2, "<aucune>") != 0)

						fwprintf(fich, L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n", url2);
				}

			}
			fprintf(fich, "}\n");
			fprintf(fich, "geometry Text{\n");
			fwprintf(fich, L"string [\"%s\"]\n", vIDC_Test1);
			fprintf(fich, "fontStyle FontStyle{\n");
			fwprintf(fich, L"family \"%s\"\n style \"%s\" \n", url3, url4);
			fwprintf(fich, L"size %s \n", vIDC_Size);
			fprintf(fich, "}\n");
			fprintf(fich, "}\n");
			fprintf(fich, "}\n");
			fprintf(fich, "},\n");
			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDC_OPTIONS:
			DialogBox(NULL, MAKEINTRESOURCE(IDD_MATIERE), hwnd, (DLGPROC)matiere);
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

/********************************************************************************************************************/
/*****************                                     Animation                                     *******************/
/********************************************************************************************************************/
LRESULT CALLBACK animPlane(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_offset1[10] = TEXT("0"), vIDC_offset2[10] = TEXT("0"), vIDC_offset3[10] = TEXT("0"),
		vIDC_minPosition1[10] = TEXT("0"), vIDC_minPosition2[10] = TEXT("0"),
		vIDC_maxPosition1[10] = TEXT("-1"), vIDC_maxPosition2[10] = TEXT("-1");
	bool autoOffset, enabled;
	char nom[10] = "animPlane";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_offset1, vIDC_offset1);
		SetDlgItemText(hwnd, IDC_offset2, vIDC_offset2);
		SetDlgItemText(hwnd, IDC_offset3, vIDC_offset3);
		SetDlgItemText(hwnd, IDC_minPosition1, vIDC_minPosition1);
		SetDlgItemText(hwnd, IDC_minPosition2, vIDC_minPosition2);
		SetDlgItemText(hwnd, IDC_maxPosition1, vIDC_maxPosition1);
		SetDlgItemText(hwnd, IDC_maxPosition2, vIDC_maxPosition2);
		CheckDlgButton(hwnd, IDC_autoOffset, BST_CHECKED);
		CheckDlgButton(hwnd, IDC_enabled, BST_CHECKED);
		
		

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam) {

		case IDOK:

			GetDlgItemText(hwnd, IDC_offset1, vIDC_offset1,20);
			GetDlgItemText(hwnd, IDC_offset2, vIDC_offset2, 20);
			GetDlgItemText(hwnd, IDC_offset3, vIDC_offset3, 20);
			GetDlgItemText(hwnd, IDC_minPosition1, vIDC_minPosition1, 20);
			GetDlgItemText(hwnd, IDC_minPosition2, vIDC_minPosition2, 20);
			GetDlgItemText(hwnd, IDC_maxPosition1, vIDC_maxPosition1, 20);
			GetDlgItemText(hwnd, IDC_maxPosition2, vIDC_maxPosition2, 20);
			if (IsDlgButtonChecked(hwnd, IDC_autoOffset) == BST_CHECKED) autoOffset = true;
			else autoOffset = false;
			if (IsDlgButtonChecked(hwnd, IDC_enabled) == BST_CHECKED) enabled = true;
			else enabled = false;
			
			

			++nb_pan;
			++nb_s;
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "DEF %s%d PlaneSensor {\n", nom, nb_pan);
			fwprintf(fich, L"maxPosition %s %s\n", vIDC_maxPosition1, vIDC_maxPosition2);
			fwprintf(fich, L"minPosition %s %s\n", vIDC_minPosition1, vIDC_minPosition2);
			fwprintf(fich, L"offset %s %s %s\n", vIDC_offset1, vIDC_offset2, vIDC_offset3);
			if (autoOffset) fprintf(fich, "autoOffset TRUE\n"); else fprintf(fich, "autoOffset FALSE\n");
			if (autoOffset) fprintf(fich, "enabled TRUE\n"); else fprintf(fich, "enabled FALSE\n");
			fprintf(fich, "}\n");
			sprintf_s(listObjet[nb_s],"%s%d", nom, nb_pan);
			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDC_OPTIONS:
			DialogBox(NULL, MAKEINTRESOURCE(IDD_MATIERE), hwnd, (DLGPROC)matiere);
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

LRESULT CALLBACK animSphere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_offset1[10] = TEXT("0"), vIDC_offset2[10] = TEXT("1"), vIDC_offset3[10] = TEXT("0"), vIDC_offset4[10] = TEXT("0");
	bool autoOffset, enabled;
	char nom[20] = "animSphere";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_offset1, vIDC_offset1);
		SetDlgItemText(hwnd, IDC_offset2, vIDC_offset2);
		SetDlgItemText(hwnd, IDC_offset3, vIDC_offset3);
		SetDlgItemText(hwnd, IDC_offset4, vIDC_offset4);
		CheckDlgButton(hwnd, IDC_autoOffset, BST_CHECKED);
		CheckDlgButton(hwnd, IDC_enabled, BST_CHECKED);
		

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam) {

		case IDOK:

			GetDlgItemText(hwnd, IDC_offset1, vIDC_offset1, 20);
			GetDlgItemText(hwnd, IDC_offset2, vIDC_offset2, 20);
			GetDlgItemText(hwnd, IDC_offset3, vIDC_offset3, 20);
			GetDlgItemText(hwnd, IDC_offset4, vIDC_offset4, 20);
			if (IsDlgButtonChecked(hwnd, IDC_autoOffset) == BST_CHECKED) autoOffset = true;
			else autoOffset = false;
			if (IsDlgButtonChecked(hwnd, IDC_enabled) == BST_CHECKED) enabled = true;
			else enabled = false;

			++nb_sph;
			++nb_s;
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "DEF %s%d SphereSensor {\n", nom, nb_sph);
			fwprintf(fich, L"offset %s %s %s %s\n", vIDC_offset1, vIDC_offset2, vIDC_offset3, vIDC_offset4);
			if (autoOffset) fprintf(fich, "autoOffset TRUE\n"); else fprintf(fich, "autoOffset FALSE\n");
			if (autoOffset) fprintf(fich, "enabled TRUE\n"); else fprintf(fich, "enabled FALSE\n");
			fprintf(fich, "}\n");
			sprintf_s(listObjet[nb_s], "%s%d", nom, nb_sph);
			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDC_OPTIONS:
			DialogBox(NULL, MAKEINTRESOURCE(IDD_MATIERE), hwnd, (DLGPROC)matiere);
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

LRESULT CALLBACK animCylindre(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR  vIDC_diskAngle[10] = TEXT("0.262"), vIDC_offset[10] = TEXT("0"),vIDC_minAngle[10] = TEXT("0"),vIDC_maxAngle[10] = TEXT("-1");
	bool autoOffset, enabled;
	char nom[20] = "animCylindre";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_offset, vIDC_offset);
		SetDlgItemText(hwnd, IDC_diskAngle, vIDC_diskAngle);
		SetDlgItemText(hwnd, IDC_minAngle, vIDC_minAngle);
		SetDlgItemText(hwnd, IDC_maxAngle, vIDC_maxAngle);
		CheckDlgButton(hwnd, IDC_autoOffset, BST_CHECKED);
		CheckDlgButton(hwnd, IDC_enabled, BST_CHECKED);
		

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam) {

		case IDOK:

			GetDlgItemText(hwnd, IDC_offset, vIDC_offset,20);
			GetDlgItemText(hwnd, IDC_diskAngle, vIDC_diskAngle,20);
			GetDlgItemText(hwnd, IDC_minAngle, vIDC_minAngle,20);
			GetDlgItemText(hwnd, IDC_maxAngle, vIDC_maxAngle,20);
			if (IsDlgButtonChecked(hwnd, IDC_autoOffset) == BST_CHECKED) autoOffset = true;
			else autoOffset = false;
			if (IsDlgButtonChecked(hwnd, IDC_enabled) == BST_CHECKED) enabled = true;
			else enabled = false;



			++nb_cyl;
			++nb_s;
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "DEF %s%d CylinderSensor {\n", nom, nb_cyl);
			fwprintf(fich, L"maxAngle %s\n", vIDC_maxAngle);
			fwprintf(fich, L"minAngle %s\n", vIDC_minAngle);
			fwprintf(fich, L"offset %s \n", vIDC_offset);
			fwprintf(fich, L"diskAngle %s \n", vIDC_diskAngle);
			if (autoOffset) fprintf(fich, "autoOffset TRUE\n"); else fprintf(fich, "autoOffset FALSE\n");
			if (autoOffset) fprintf(fich, "enabled TRUE\n"); else fprintf(fich, "enabled FALSE\n");
			fprintf(fich, "}\n");
			sprintf_s(listObjet[nb_s], "%s%d", nom, nb_cyl);
			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDC_OPTIONS:
			DialogBox(NULL, MAKEINTRESOURCE(IDD_MATIERE), hwnd, (DLGPROC)matiere);
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

/********************************************************************************************************************/
/*****************                                     LUMIERE                                    *******************/
/********************************************************************************************************************/
LRESULT CALLBACK lum_directionnelle(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10] = TEXT("0"), vIDC_Dy[10] = TEXT("0"), vIDC_Dz[10] = TEXT("0");
	TCHAR vIDC_ambientIntensity[10] = TEXT("0.2"), vIDC_intensity[10] = TEXT("1"),
		vIDC_directionX[10] = TEXT("0"), vIDC_directionY[10] = TEXT("1"), vIDC_directionZ[10] = TEXT("1"),
		vIDC_colorR[10] = TEXT("1"), vIDC_colorG[10] = TEXT("0"), vIDC_colorB[10] = TEXT("0");
	
	char nom[10] = "lumD";

	switch (msg) {
	case WM_INITDIALOG:
		GetDlgItemText(hwnd, IDC_Dx, vIDC_Dx, 10);
		GetDlgItemText(hwnd, IDC_Dy, vIDC_Dy, 10);
		GetDlgItemText(hwnd, IDC_Dz, vIDC_Dz, 10);
		SetDlgItemText(hwnd, IDC_ambientIntensity, vIDC_ambientIntensity);
		SetDlgItemText(hwnd, IDC_intensity, vIDC_intensity);
		SetDlgItemText(hwnd, IDC_directionX, vIDC_directionX);
		SetDlgItemText(hwnd, IDC_directionY, vIDC_directionY);
		SetDlgItemText(hwnd, IDC_directionZ, vIDC_directionZ);
		SetDlgItemText(hwnd, IDC_colorR, vIDC_colorR);
		SetDlgItemText(hwnd, IDC_colorG, vIDC_colorG);
		SetDlgItemText(hwnd, IDC_colorB, vIDC_colorB);
		CheckDlgButton(hwnd, IDC_ACTIVE, BST_CHECKED);

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam)  {

		case IDOK:
			GetDlgItemText(hwnd, IDC_Dx, vIDC_Dx, 10);
			GetDlgItemText(hwnd, IDC_Dy, vIDC_Dy, 10);
			GetDlgItemText(hwnd, IDC_Dz, vIDC_Dz, 10);
			GetDlgItemText(hwnd, IDC_ambientIntensity, vIDC_ambientIntensity, 10);
			GetDlgItemText(hwnd, IDC_intensity, vIDC_intensity, 10);
			GetDlgItemText(hwnd, IDC_directionX, vIDC_directionX, 10);
			GetDlgItemText(hwnd, IDC_directionY, vIDC_directionY, 10);
			GetDlgItemText(hwnd, IDC_directionZ, vIDC_directionZ, 10);
			GetDlgItemText(hwnd, IDC_colorR, vIDC_colorR, 10);
			GetDlgItemText(hwnd, IDC_colorG, vIDC_colorG, 10);
			GetDlgItemText(hwnd, IDC_colorB, vIDC_colorB, 10);

		
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "DirectionalLight {\n");
			fwprintf(fich, L"ambientIntensity %s\n", vIDC_ambientIntensity);
			fwprintf(fich, L"color %s %s %s\n", vIDC_colorR, vIDC_colorG, vIDC_colorB);
			fwprintf(fich, L"direction %s %s %s\n", vIDC_directionX, vIDC_directionY, vIDC_directionZ);
			fwprintf(fich, L"intensity %s\n", vIDC_intensity);
			if (IsDlgButtonChecked(hwnd, IDC_ACTIVE) == BST_UNCHECKED) fprintf(fich, "on FALSE\n");
			fprintf(fich, "}\n");
			
			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

LRESULT CALLBACK lum_ponctuelle(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_ambientIntensity[10] = TEXT("0"), vIDC_intensity[10] = TEXT("1"), vIDC_RADIUS[10] = TEXT("100"),
		vIDC_attenuationX[10] = TEXT("1"), vIDC_attenuationY[10] = TEXT("0"), vIDC_attenuationZ[10] = TEXT("0"),
		vIDC_locationX[10] = TEXT("0"), vIDC_locationY[10] = TEXT("0"), vIDC_locationZ[10] = TEXT("0"),
		vIDC_colorR[10] = TEXT("1"), vIDC_colorG[10] = TEXT("1"), vIDC_colorB[10] = TEXT("1");
	char nom[10] = "lumP";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_ambientIntensity, vIDC_ambientIntensity);
		SetDlgItemText(hwnd, IDC_intensity, vIDC_intensity);
		SetDlgItemText(hwnd, IDC_RADIUS, vIDC_RADIUS);
		SetDlgItemText(hwnd, IDC_attenuationX, vIDC_attenuationX);
		SetDlgItemText(hwnd, IDC_attenuationY, vIDC_attenuationY);
		SetDlgItemText(hwnd, IDC_attenuationZ, vIDC_attenuationZ);
		SetDlgItemText(hwnd, IDC_locationX, vIDC_locationX);
		SetDlgItemText(hwnd, IDC_locationY, vIDC_locationY);
		SetDlgItemText(hwnd, IDC_locationZ, vIDC_locationZ);
		SetDlgItemText(hwnd, IDC_colorR, vIDC_colorR);
		SetDlgItemText(hwnd, IDC_colorG, vIDC_colorG);
		SetDlgItemText(hwnd, IDC_colorB, vIDC_colorB);
		CheckDlgButton(hwnd, IDC_ACTIVE, BST_CHECKED);

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam)  {

		case IDOK:
			GetDlgItemText(hwnd, IDC_ambientIntensity, vIDC_ambientIntensity, 10);
			GetDlgItemText(hwnd, IDC_intensity, vIDC_intensity, 10);
			GetDlgItemText(hwnd, IDC_RADIUS, vIDC_RADIUS, 10);
			GetDlgItemText(hwnd, IDC_attenuationX, vIDC_attenuationX, 10);
			GetDlgItemText(hwnd, IDC_attenuationY, vIDC_attenuationY, 10);
			GetDlgItemText(hwnd, IDC_attenuationZ, vIDC_attenuationZ, 10);
			GetDlgItemText(hwnd, IDC_locationX, vIDC_locationX, 10);
			GetDlgItemText(hwnd, IDC_locationY, vIDC_locationY, 10);
			GetDlgItemText(hwnd, IDC_locationZ, vIDC_locationZ, 10);
			GetDlgItemText(hwnd, IDC_colorR, vIDC_colorR, 10);
			GetDlgItemText(hwnd, IDC_colorG, vIDC_colorG, 10);
			GetDlgItemText(hwnd, IDC_colorB, vIDC_colorB, 10);

			
			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "PointLight {\n");
			fwprintf(fich, L"ambientIntensity %s \n", vIDC_ambientIntensity);
			fwprintf(fich, L"color %s %s %s \n", vIDC_colorR, vIDC_colorG, vIDC_colorB);
			fwprintf(fich, L"location %s %s %s \n", vIDC_locationX, vIDC_locationY, vIDC_locationZ);
			fwprintf(fich, L"attenuation %s %s %s \n", vIDC_attenuationX, vIDC_attenuationY, vIDC_attenuationZ);
			fwprintf(fich, L"intensity %s \n", vIDC_intensity);
			fwprintf(fich,	L"radius %s \n", vIDC_RADIUS);
			if (IsDlgButtonChecked(hwnd, IDC_ACTIVE) == BST_UNCHECKED) fprintf(fich, "on FALSE\n");
			fprintf(fich, "}\n");

			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

LRESULT CALLBACK lum_spot(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_ambientIntensity[10] = TEXT("0.2"), vIDC_intensity[10] = TEXT("1"),
		vIDC_RADIUS[10] = TEXT("100"), vIDC_BEAMWIDTH[10] = TEXT("1.570796"), vIDC_CUTOFFANGLE[10] = TEXT("0.785398"),
		vIDC_directionX[10] = TEXT("0"), vIDC_directionY[10] = TEXT("0"), vIDC_directionZ[10] = TEXT("1"),
		vIDC_locationX[10] = TEXT("0"), vIDC_locationY[10] = TEXT("0"), vIDC_locationZ[10] = TEXT("0"),
		vIDC_attenuationX[10] = TEXT("1"), vIDC_attenuationY[10] = TEXT("0"), vIDC_attenuationZ[10] = TEXT("0"),
		vIDC_colorR[10] = TEXT("1"), vIDC_colorG[10] = TEXT("1"), vIDC_colorB[10] = TEXT("1");
	char nom[10] = "lumS";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_ambientIntensity, vIDC_ambientIntensity);
		SetDlgItemText(hwnd, IDC_intensity, vIDC_intensity);
		SetDlgItemText(hwnd, IDC_RADIUS, vIDC_RADIUS);
		SetDlgItemText(hwnd, IDC_BEAMWIDTH, vIDC_BEAMWIDTH);
		SetDlgItemText(hwnd, IDC_CUTOFFANGLE, vIDC_CUTOFFANGLE);
		SetDlgItemText(hwnd, IDC_directionX, vIDC_directionX);
		SetDlgItemText(hwnd, IDC_directionY, vIDC_directionY);
		SetDlgItemText(hwnd, IDC_directionZ, vIDC_directionZ);
		SetDlgItemText(hwnd, IDC_locationX, vIDC_locationX);
		SetDlgItemText(hwnd, IDC_locationY, vIDC_locationY);
		SetDlgItemText(hwnd, IDC_locationZ, vIDC_locationZ);
		SetDlgItemText(hwnd, IDC_attenuationX, vIDC_attenuationX);
		SetDlgItemText(hwnd, IDC_attenuationY, vIDC_attenuationY);
		SetDlgItemText(hwnd, IDC_attenuationZ, vIDC_attenuationZ);
		SetDlgItemText(hwnd, IDC_colorR, vIDC_colorR);
		SetDlgItemText(hwnd, IDC_colorG, vIDC_colorG);
		SetDlgItemText(hwnd, IDC_colorB, vIDC_colorB);
		CheckDlgButton(hwnd, IDC_ACTIVE, BST_CHECKED);

		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam)  {

		case IDOK:
			GetDlgItemText(hwnd, IDC_ambientIntensity, vIDC_ambientIntensity, 10);
			GetDlgItemText(hwnd, IDC_intensity, vIDC_intensity, 10);
			GetDlgItemText(hwnd, IDC_RADIUS, vIDC_RADIUS,10);
			GetDlgItemText(hwnd, IDC_BEAMWIDTH, vIDC_BEAMWIDTH,10);
			GetDlgItemText(hwnd, IDC_CUTOFFANGLE, vIDC_CUTOFFANGLE,10);
			GetDlgItemText(hwnd, IDC_directionX, vIDC_directionX, 10);
			GetDlgItemText(hwnd, IDC_directionY, vIDC_directionY, 10);
			GetDlgItemText(hwnd, IDC_directionZ, vIDC_directionZ, 10);
			GetDlgItemText(hwnd, IDC_locationX, vIDC_locationX,10);
			GetDlgItemText(hwnd, IDC_locationY, vIDC_locationY,10);
			GetDlgItemText(hwnd, IDC_locationZ, vIDC_locationZ,10);
			GetDlgItemText(hwnd, IDC_attenuationX, vIDC_attenuationX, 10);
			GetDlgItemText(hwnd, IDC_attenuationY, vIDC_attenuationY, 10);
			GetDlgItemText(hwnd, IDC_attenuationZ, vIDC_attenuationZ, 10);
			GetDlgItemText(hwnd, IDC_colorR, vIDC_colorR, 10);
			GetDlgItemText(hwnd, IDC_colorG, vIDC_colorG, 10);
			GetDlgItemText(hwnd, IDC_colorB, vIDC_colorB, 10);


			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "SpotLight {\n");
			fwprintf(fich, L"ambientIntensity %s \n", vIDC_ambientIntensity);
			fwprintf(fich, L"beamWidth %s \n", vIDC_BEAMWIDTH);
			fwprintf(fich, L"cutOffAngle %s \n", vIDC_ambientIntensity);
			fwprintf(fich, L"color %s %s %s \n", vIDC_colorR, vIDC_colorG, vIDC_colorB);
			fwprintf(fich, L"direction %s %s %s \n", vIDC_directionX, vIDC_directionY, vIDC_directionZ);
			fwprintf(fich, L"location %s %s %s \n", vIDC_locationX, vIDC_locationY, vIDC_locationZ);
			fwprintf(fich, L"attenuation %s %s %s \n", vIDC_attenuationX, vIDC_attenuationY, vIDC_attenuationZ);
			fwprintf(fich, L"intensity %s \n", vIDC_intensity);
			fwprintf(fich, L"radius %s \n", vIDC_RADIUS);
			if (IsDlgButtonChecked(hwnd, IDC_ACTIVE) == BST_UNCHECKED) fprintf(fich, "on FALSE\n");
			fprintf(fich, "}\n");

			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}

/********************************************************************************************************************/
/*****************                                     FOND                                       *******************/
/********************************************************************************************************************/
LRESULT CALLBACK fond(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_SAx[10] = TEXT("0.0"), vIDC_SAy[10] = TEXT("1.1"),vIDC_SAz[10] = TEXT("1.57"),
		vIDC_GAx[10] = TEXT("0.0"), vIDC_GAy[10] = TEXT("1.1"), vIDC_GAz[10] = TEXT("1.57"),

		vIDC_SC11[10] = TEXT("0"), vIDC_SC12[10] = TEXT("0"), vIDC_SC13[10] = TEXT("1"),
		vIDC_SC21[10] = TEXT("0"), vIDC_SC22[10] = TEXT("0"), vIDC_SC23[10] = TEXT("0.5"),
		vIDC_SC31[10] = TEXT("0.8"), vIDC_SC32[10] = TEXT("0.8"), vIDC_SC33[10] = TEXT("1"),
		vIDC_SC41[10] = TEXT("0.9"), vIDC_SC42[10] = TEXT("0.9"), vIDC_SC43[10] = TEXT("0.9"),

		vIDC_GC11[10] = TEXT("0.8"), vIDC_GC12[10] = TEXT("0.8"), vIDC_GC13[10] = TEXT("0.4"),
		vIDC_GC21[10] = TEXT("0.8"), vIDC_GC22[10] = TEXT("0.8"), vIDC_GC23[10] = TEXT("0.4"),
		vIDC_GC31[10] = TEXT("0.8"), vIDC_GC32[10] = TEXT("0.8"), vIDC_GC33[10] = TEXT("0.7"),
		vIDC_GC41[10] = TEXT("0.8"), vIDC_GC42[10] = TEXT("0.8"), vIDC_GC43[10] = TEXT("0.8")
		;
	char nom[10] = "fon";

	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemText(hwnd, IDC_SAx, vIDC_SAx);
		SetDlgItemText(hwnd, IDC_SAy, vIDC_SAy);
		SetDlgItemText(hwnd, IDC_SAz, vIDC_SAz);
		SetDlgItemText(hwnd, IDC_SC11, vIDC_SC11);
		SetDlgItemText(hwnd, IDC_SC12, vIDC_SC12);
		SetDlgItemText(hwnd, IDC_SC13, vIDC_SC13);
		SetDlgItemText(hwnd, IDC_SC21, vIDC_SC21);
		SetDlgItemText(hwnd, IDC_SC22, vIDC_SC22);
		SetDlgItemText(hwnd, IDC_SC23, vIDC_SC23);
		SetDlgItemText(hwnd, IDC_SC31, vIDC_SC31);
		SetDlgItemText(hwnd, IDC_SC32, vIDC_SC32);
		SetDlgItemText(hwnd, IDC_SC33, vIDC_SC33);
		SetDlgItemText(hwnd, IDC_SC41, vIDC_SC41);
		SetDlgItemText(hwnd, IDC_SC42, vIDC_SC42);
		SetDlgItemText(hwnd, IDC_SC43, vIDC_SC43);

		SetDlgItemText(hwnd, IDC_GAx, vIDC_GAx);
		SetDlgItemText(hwnd, IDC_GAy, vIDC_GAy);
		SetDlgItemText(hwnd, IDC_GAz, vIDC_GAz);
		SetDlgItemText(hwnd, IDC_GC11, vIDC_GC11);
		SetDlgItemText(hwnd, IDC_GC12, vIDC_GC12);
		SetDlgItemText(hwnd, IDC_GC13, vIDC_GC13);
		SetDlgItemText(hwnd, IDC_GC21, vIDC_GC21);
		SetDlgItemText(hwnd, IDC_GC22, vIDC_GC22);
		SetDlgItemText(hwnd, IDC_GC23, vIDC_GC23);
		SetDlgItemText(hwnd, IDC_GC31, vIDC_GC31);
		SetDlgItemText(hwnd, IDC_GC32, vIDC_GC32);
		SetDlgItemText(hwnd, IDC_GC33, vIDC_GC33);
		SetDlgItemText(hwnd, IDC_GC41, vIDC_GC41);
		SetDlgItemText(hwnd, IDC_GC42, vIDC_GC42);
		SetDlgItemText(hwnd, IDC_GC43, vIDC_GC43);
		



		return 0;
	case WM_COMMAND:
		switch LOWORD(wParam) {

		case IDOK:
			GetDlgItemText(hwnd, IDC_SAx, vIDC_SAx,10);
			GetDlgItemText(hwnd, IDC_SAy, vIDC_SAy, 10);
			GetDlgItemText(hwnd, IDC_SAz, vIDC_SAz, 10);
			GetDlgItemText(hwnd, IDC_SC11, vIDC_SC11, 10);
			GetDlgItemText(hwnd, IDC_SC12, vIDC_SC12, 10);
			GetDlgItemText(hwnd, IDC_SC13, vIDC_SC13, 10);
			GetDlgItemText(hwnd, IDC_SC21, vIDC_SC21, 10);
			GetDlgItemText(hwnd, IDC_SC22, vIDC_SC22, 10);
			GetDlgItemText(hwnd, IDC_SC23, vIDC_SC23, 10);
			GetDlgItemText(hwnd, IDC_SC31, vIDC_SC31, 10);
			GetDlgItemText(hwnd, IDC_SC32, vIDC_SC32, 10);
			GetDlgItemText(hwnd, IDC_SC33, vIDC_SC33, 10);
			GetDlgItemText(hwnd, IDC_SC41, vIDC_SC41, 10);
			GetDlgItemText(hwnd, IDC_SC42, vIDC_SC42, 10);
			GetDlgItemText(hwnd, IDC_SC43, vIDC_SC43, 10);

			GetDlgItemText(hwnd, IDC_GAx, vIDC_GAx, 10);
			GetDlgItemText(hwnd, IDC_GAy, vIDC_GAy, 10);
			GetDlgItemText(hwnd, IDC_GAz, vIDC_GAz, 10);
			GetDlgItemText(hwnd, IDC_GC11, vIDC_GC11, 10);
			GetDlgItemText(hwnd, IDC_GC12, vIDC_GC12, 10);
			GetDlgItemText(hwnd, IDC_GC13, vIDC_GC13, 10);
			GetDlgItemText(hwnd, IDC_GC21, vIDC_GC21, 10);
			GetDlgItemText(hwnd, IDC_GC22, vIDC_GC22, 10);
			GetDlgItemText(hwnd, IDC_GC23, vIDC_GC23, 10);
			GetDlgItemText(hwnd, IDC_GC31, vIDC_GC31, 10);
			GetDlgItemText(hwnd, IDC_GC32, vIDC_GC32, 10);
			GetDlgItemText(hwnd, IDC_GC33, vIDC_GC33, 10);
			GetDlgItemText(hwnd, IDC_GC41, vIDC_GC41, 10);
			GetDlgItemText(hwnd, IDC_GC42, vIDC_GC42, 10);
			GetDlgItemText(hwnd, IDC_GC43, vIDC_GC43, 10);


			fopen_s(&fich, "toto.wrl", "a");
			fprintf(fich, "Background  {\n");
			fwprintf(fich, L"skyAngle [%s, %s, %s]\n", vIDC_SAx,vIDC_SAy,vIDC_SAz);
			fwprintf(fich, L"skyColor [ %s %s %s, %s %s %s, %s %s %s, %s %s %s]\n", vIDC_SC11,vIDC_SC12,vIDC_SC13,vIDC_SC21, vIDC_SC22,vIDC_SC23, vIDC_SC31,vIDC_SC32, vIDC_SC33,vIDC_SC41, vIDC_SC42, vIDC_SC43);
			fwprintf(fich, L"groundAngle [%s, %s, %s]\n", vIDC_SAx, vIDC_SAy, vIDC_SAz);
			fwprintf(fich, L"groundColor [ %s %s %s, %s %s %s, %s %s %s, %s %s %s]\n", vIDC_GC11, vIDC_GC12, vIDC_GC13, vIDC_GC21, vIDC_GC22, vIDC_GC23, vIDC_GC31, vIDC_GC32, vIDC_GC33, vIDC_GC41, vIDC_GC42, vIDC_GC43);
			fprintf(fich, "}\n");

			fclose(fich);
			EndDialog(hwnd, 1);
			return 0;

		case IDCANCEL:

			EndDialog(hwnd, 0);
			return 0;
		}
		return 0;

	}
	return 0;
}




LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     
     HMENU      hMenu ;
     char nom[20]="objet";
	 
	 
     switch (message)
     {
     case WM_COMMAND:
          hMenu = GetMenu (hwnd) ;
          
          switch (LOWORD (wParam))
          {
         

          case ID_EDITION_QUIT :
			   fopen_s(&fich,"toto.wrl","a");
			   fprintf(fich,"] }\n");
			   // nb_pan  nombre de sensor plan
			   for (int k = 1; k <= nb_pan;k++) {
						   for (int j = 1; j<= nb_objet; j++) {
							   fprintf(fich,"ROUTE animPlane%d.translation_changed TO objet%d.set_translation\n", k, j);
						   }
					}
			   // nb_sph nombre de sensor sphère
			   for (int k = 1; k <= nb_sph; k++) {
				   for (int j = 1; j <= nb_objet; j++) {
					   fprintf(fich, "ROUTE animSphere%d.rotation_changed TO objet%d.set_rotation\n", k, j);
				   }
			   }

			   // nb_cyl nombre de sensor cylindre
			   for (int k = 1; k <= nb_cyl; k++) {
						   for (int j = 1; j <= nb_objet; j++) {
							   fprintf(fich, "ROUTE animCylindre%d.rotation_changed TO objet%d.set_rotation\n", k, j);
						   }
			   }
			   fprintf(fich,"\n Inline{\n");
			   fprintf(fich,"url \"axes.wrl\" }\n");
			   SendMessage (hwnd, WM_CLOSE, 0, 0) ;
			   fclose(fich);
			   return 0;
			  
          case ID_EDITION_NEW :
			   fopen_s(&fich,"toto.wrl","w");
			   fprintf(fich,"#VRML V2.0 utf8 \n");
			   fprintf(fich,"Group { \n");
			   fprintf(fich,"children [\n");
			   
			   fclose(fich);
			   EnableMenuItem(hMenu, ID_EDITION_NEW, MF_GRAYED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_CYLINDRE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_SPHERE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_BOITE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_CONE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_TEXTE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_DIRECTIONNELLE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_PONCTUELLE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_SPOT, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_ANIMATION_SPH, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_ANIMATION_CYL, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_ANIMATION_PAN, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_FOND_FOND, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_EDITION_QUIT, MF_ENABLED);
			   InvalidateRect (hwnd, NULL, TRUE) ;
               return 0;

          
		  
          case ID_GEOMETRIE_CYLINDRE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CYLINDRE), hwnd, (DLGPROC)cylindre);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_SPHERE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_SPHERE), hwnd, (DLGPROC)sphere);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_BOITE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_BOITE), hwnd, (DLGPROC)boite);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
			   
		  case ID_GEOMETRIE_CONE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CONE), hwnd, (DLGPROC)cone);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
			   
			case ID_GEOMETRIE_TEXTE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_TEXTE), hwnd, (DLGPROC)texte);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
		  
			case ID_LUMIERE_DIRECTIONNELLE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_DIRECTIONNELLE), hwnd, (DLGPROC)lum_directionnelle);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_PONCTUELLE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_PONCTUELLE), hwnd, (DLGPROC)lum_ponctuelle);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_SPOT: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_SPOT), hwnd, (DLGPROC)lum_spot);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_ANIMATION_SPH:
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_SphereSensor), hwnd, (DLGPROC)animSphere);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_ANIMATION_PAN:
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_PaneSensor), hwnd, (DLGPROC)animPlane);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
			case ID_ANIMATION_CYL:

				DialogBox(NULL,MAKEINTRESOURCE(IDD_CylinderSensor), hwnd, (DLGPROC)animCylindre);
				InvalidateRect(hwnd, NULL, TRUE);
				return 0;


			case ID_FOND_FOND: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_FOND), hwnd, (DLGPROC)fond);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_AIDE: 
			  
              // DialogBox(NULL,MAKEINTRESOURCE(IDD_AIDE), hwnd, (DLGPROC)aide);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  }
          
          return 0 ;
		  case WM_CLOSE:
	           	DestroyWindow(hwnd);
		
			case WM_DESTROY:
			  PostQuitMessage(0);
			return 0;
     }
         
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}


