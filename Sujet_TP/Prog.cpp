#include <windows.h>
#include "resource.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool choix_texture;
bool texture=false;
HWND hwndcombo, hwndcombo2;

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




char urll[30],url2[30];


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

LRESULT CALLBACK cylindre(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0"),vIDC_Hauteur[10]=TEXT("2.0");
	char nom[10]="objet";
    
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
			   EnableMenuItem(hMenu, ID_ANIMATION_TRANSLATION, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_ANIMATION_ROTATION, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_FOND_FOND, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_EDITION_QUIT, MF_ENABLED);
			   InvalidateRect (hwnd, NULL, TRUE) ;
               return 0;

          
		  
          case ID_GEOMETRIE_CYLINDRE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CYLINDRE), hwnd, (DLGPROC)cylindre);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_SPHERE: 
			  
              // DialogBox(NULL,MAKEINTRESOURCE(IDD_SPHERE), hwnd, (DLGPROC)sphere);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_BOITE: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_BOITE), hwnd, (DLGPROC)boite);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_CONE: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_CONE), hwnd, (DLGPROC)cone);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_GEOMETRIE_TEXTE: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_TEXTE), hwnd, (DLGPROC)texte);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
		  
			case ID_LUMIERE_DIRECTIONNELLE: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_DIRECTIONNELLE), hwnd, (DLGPROC)lum_directionnelle);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_PONCTUELLE: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_PONCTUELLE), hwnd, (DLGPROC)lum_ponctuelle);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_SPOT: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_SPOT), hwnd, (DLGPROC)lum_spot);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_ANIMATION_TRANSLATION: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_ANIMTRANSLATE), hwnd, (DLGPROC)animTranslate);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_ANIMATION_ROTATION: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_ANIMROTATE), hwnd, (DLGPROC)animRotate);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;


			case ID_FOND_FOND: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_FOND), hwnd, (DLGPROC)fond);
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


