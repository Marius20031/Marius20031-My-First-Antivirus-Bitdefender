#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define sev 17
#define ther 13
int global;

///SUBPROGRAME TASK1:
void verificari(char *proiectie, int *ok, char *buffer)
{
	if (strstr(buffer, "=com"))
		*ok = 1;
	if (strstr(buffer, "mod_"))
		*ok = 1;
	//if (strstr(buffer, "login"))
		//*ok = 1;
	//if (strstr(buffer, "com."))
		//*ok = 1;

	if (strstr(proiectie, ".dat") || strstr(proiectie, ".pdf"))
		*ok = 1;
	if (strstr(proiectie, ".bin") || strstr(proiectie, "Mozi.m"))
		*ok = 1;
	if (strstr(proiectie, ".doc") || strstr(proiectie, ".i"))
		*ok = 1;
	if (strstr(proiectie, ".css") || strstr(proiectie, ".doc"))
		*ok = 1;
	//if (strstr(proiectie, ".arm"))
		//*ok = 1;
	if (strstr(proiectie, "yyy") || strstr(proiectie, "www3"))
		*ok = 1;

	if (strstr(buffer, "'") || strstr(proiectie, ".htm")) // e safe
		*ok = 0;
	if (strstr(buffer, "/exe/"))
		*ok = 1;
	if (strstr(buffer, ".html")) // e safe
		*ok = 0;
	if (strstr(proiectie, ".exe\n") || strstr(proiectie, ".bin\n"))
		*ok = 1;
	int aux = strlen(proiectie);
	if (strstr(proiectie, ".sh\n"))
		*ok = 1;
}

void verifphising(char *p, int *ok)
{
		if (strstr(p, "www") && !strstr(p, "www."))
			*ok = 1; //trb www.
		//if (strstr(p, "facebook") && strcmp(p, "facebook.com") != 0)
			//*ok = 1; //facebook are doar facebook.com restul sunt phising
		//if (strstr(p, "x"))
			//*ok = 1; //site.uri cu x sunt cam sus in general

		if (strstr(p, "paypal") && strcmp(p, "paypal.com") != 0)
			*ok = 1; //paypal are doar paypal.com restul sunt phising
		if (strstr(p, "apple") && strcmp(p, "itunes.apple.com") != 0)
			*ok = 1; //apple are doar apple.com restul sunt phising
		if (strstr(p, "google") && strcmp(p, "google.com") != 0)
			*ok = 1; //apple are doar apple.com restul sunt phising
		if (strstr(p, "ebay") && strcmp(p, "ebay.com") != 0)
			*ok = 1; //apple are doar apple.com restul sunt phising
		if (strstr(p, "samsung") && strcmp(p, "samsung.com") != 0)
			*ok = 1; //apple are doar apple.com restul sunt phising
		if (strstr(p, "bing") && strcmp(p, "bing.com") != 0)
			*ok = 1; //apple are doar apple.com restul sunt phising

		/*
		if (strstr(p, "paypal.com"))
			*ok = 0; //paypal are doar paypal.com restul sunt phising
		if (strstr(p, "apple.com"))
			*ok = 0; //apple are doar apple.com restul sunt phising
		if (strstr(p, "google.com"))
			*ok = 0; //apple are doar apple.com restul sunt phising
		if (strstr(p, "ebay.com"))
			*ok = 0; //apple are doar apple.com restul sunt phising
		if (strstr(p, "samsung.com"))
			*ok = 0; //apple are doar apple.com restul sunt phising
		if (strstr(p, "bing.com"))
			*ok = 0; //apple are doar apple.com restul sunt phising
		*/
		//if (strstr(proiectie, ".pl\n"))
		//*ok = 1;
}

void verifconsdomain(char *p, int *ok, int *t)
{
	char vocale[] = "aeiou";
	int  j = 0, auxi = 0;
	while (p[j] != '.') {  //pana la punct daca are consoane e sus
		if (!strchr(vocale, p[j]))
			auxi++;
		j++;
	}
	if (auxi == j)
		*ok = 1;
}

void longfunction(char *proiectie, int *ok, char *buffer)
{
	if (strstr(proiectie, ".sh\n") || strstr(proiectie, ".exe\n"))
		*ok = 1;
	if (strstr(proiectie, ".bin\n"))
		*ok = 1;
	if (strstr(buffer, "~") || strstr(buffer, "'"))
		*ok = 0;
	if (strstr(buffer, "=\n"))
		*ok = 1;
}

void verifterminator(char *buffer, int *ok)
{
	//printf("%s",buffer);
	char *string, *proiectie, *verif, *sirt;
	string = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	proiectie = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	verif = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

	strcpy(string, buffer);
	char sep[] = "/";
	char *p = strtok(string, sep);

	strcpy(verif, p);

	int num = 1, y = 0, t = -1, m = 0, v = 0, variabila = 0;
	while (p) {
		strcpy(proiectie, p);
		if (num == 1) {
			char *r = "0123456789";
			for (int j = 0; j < strlen(p); j++) {
				if (strchr(r, p[j])) {
					if (v == 0 && variabila >= 3) /// inainte de primul.
						t = 1;
					y++;
					variabila++;
				}
				if (v == 0 && m >= 2) // x e suspect in url.uri
					t = 1;
				if (p[j] == '.') {
					v++;
					variabila++;
				}
				if (p[j] == 'x')
					m++;
				//if (v >= 4)
					//*ok = 1;
				verifphising(p, ok);
			}
			if (variabila == strlen(p))
				t = 1;
			if (strstr(p, ":"))
				t = 1;
			if (strcmp(p, "groups.google.com") == 0) // e cunoscut
				t = 0;
			if (strcmp(p, "bing.com") == 0) // e cunoscut
				t = 0;
		}
		if (num == 2) {
			if (strcmp(p, "https") == 0)
				t = 1;
		}
	p = strtok(NULL, sep);
	num++;
	}

	if (*ok == 1 && y == 0 && t != 0)
		t = 1;

	if (strcmp(verif, buffer) == 0)
		*ok = 1;

	verificari(proiectie, ok, buffer);

	if (t == 1 && *ok == 0)
		*ok = 1;

	longfunction(proiectie, ok, buffer);

	if (t == 0)
		*ok = 0;

	//if (strstr(proiectie, "=\n"))
		//*ok = 1;

	if (verif)
		free(verif);
	if (string)
		free(string);
	if (proiectie)
		free(proiectie);
	//printf("%s",proiectie);
}

void veriftoshirodb(char *buffer, int *ok)
{
    //printf("test");
	FILE *fin;
	fin = fopen("Toshiro.txt", "r");

	char *citire;
	citire = (char *)malloc(5511 * sizeof(char));
	while (fgets(citire, 5511, fin)) {
		citire[strlen(citire) - 1] = '\0';
		///printf("%s\n",citire);
		if (strstr(buffer, citire)) {
			printf("%s\n", citire);
			//*ok = 1;
			//printf("%s\n",buffer);
			break;
		}
	}

	if (citire)
		free(citire);
	//*ok=0;
	fclose(fin);
}

void verifbazaa(char *buffer, int *ok)
{
    //printf("test");
	FILE *fin;
	fin = fopen("SUM.txt", "r");

	char *citire;
	citire = (char *)malloc(5511 * sizeof(char));
	while (fgets(citire, 5511, fin)) {
		citire[strlen(citire) - 1] = '\0';
		///printf("%s\n",citire);
		if (strstr(buffer, citire)) {
			printf("%s\n", citire);
			//*ok = 1;
			//printf("%s\n",buffer);
			break;
		}
	}

	if (citire)
		free(citire);
	//*ok=0;
	fclose(fin);
}

void verifbaza(char *buffer, int *ok)
{
    //printf("test");
	FILE *fin;
	fin = fopen("data/urls/domains_database", "r");

	FILE *ffin;
	ffin = fopen("Toshiro_db.txt", "r");

	char *citire;
	citire = (char *)malloc(5511 * sizeof(char));
	while (fgets(citire, 5511, fin)) {
		citire[strlen(citire) - 1] = '\0';
		if (strstr(buffer, citire)) {
			//printf("%s\n",citire);
			*ok = 1;
			break;
		}
	}

	while (fgets(citire, 5511, ffin)) {
		citire[strlen(citire) - 1] = '\0';
		if (strstr(buffer, citire)) {
			//printf("%s\n",citire);
			*ok = 1;
			break;
		}
	}

	if (citire)
		free(citire);
	//*ok=0;
	fclose(fin);
	fclose(ffin);
}

void verifstrcmp(char *buffer, int *ok)
{
    //printf("test");
	FILE *fin;
	fin = fopen("strcmp.txt", "r");

	char *citire;

	char *proiectie = strtok(buffer, "/");

	//printf("%s", proiectie);
	citire = (char *)malloc(5511 * sizeof(char));
	while (fgets(citire, 5511, fin)) {
		citire[strlen(citire) - 1] = '\0';
		//printf("%s - %s\n",proiectie, citire);
		if (strstr(proiectie, citire)) {
			printf("%s\n",citire);
			//*ok = 1;
			//break;
		}
	}

	if (citire)
		free(citire);
	//*ok=0;
	fclose(fin);
}

void verifdomain(char *buffer, int *ok)
{
	char *string, *proiectie, *verif;
	string = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	proiectie = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	verif = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

	strcpy(string, buffer);
	char sep[] = "/";
	char *p = strtok(string, sep);
	strcpy(verif, p);
	strcpy(proiectie, p);
	FILE *fin;
	fin = fopen("Isagi_db.txt", "r");
	char *citire;
	int lungstring = strlen(proiectie);

	citire = (char *)malloc(5511 * sizeof(char));

	int k = 0;
	int neg = 0;
	while (fgets(citire, 5511, fin)) {
		citire[strlen(citire) - 1] = '\0';
	    char *pointer = strtok(citire, ".");
		if (strstr(proiectie, pointer)) {
			//printf("%s\n", proiectie);
			neg = -1;
		}
	}

	fclose(fin);
	fin = fopen("Isagi_db.txt", "r");

	while (fgets(citire, 5511, fin)) {
		citire[strlen(citire) - 1] = '\0';
		int lungsubstring = strlen(citire);
		int okish = 1;
		if (lungsubstring <= lungstring) {
			for (int i = 0; i < lungsubstring; i++) {
				if (citire[i] != proiectie[i + lungstring - lungsubstring]) {
					okish = 0;
					break;
				}
			}
	///daca nu gaseste dar exista google.com.ok-mere.pere.com -> phising
		if (okish == 1) {
			//printf("%s\n", proiectie);
			//global++;
			k = 1;
		}
		}
	}

	if (k == 1)
		*ok = 0;
	if (k == 0 && neg == -1) {
		//printf("%s",buffer);
		*ok = 1;
	}

	if ((int)*(proiectie + 0) == 39)
		*ok = 0;

	if (verif)
		free(verif);
	if (string)
		free(string);
	if (proiectie)
		free(proiectie);
	//printf("%s",proiectie);

	if (citire)
		free(citire);
	//*ok=0;
	fclose(fin);
}

void soltask1(char *buffer, int *ok)
{
	///recunoastem daca are la final .exe sau cv
	///verificam daca e in baza de date
	int semafor = 0;
	verifterminator(buffer, &semafor);
	verifbaza(buffer, &semafor);
	verifdomain(buffer, &semafor);
	verifbazaa(buffer, &semafor);
	//verifToshirodb(buffer, &semafor);
	*ok = semafor;
}

void task1(void)
{
	FILE *fin, *fout;

	fout = fopen("urls-predictions.out", "w");
	fin = fopen("data/urls/urls.in", "r");

	char *buffer = NULL;
	int ok;
	///task1
	buffer = (char *)malloc(5511 * sizeof(char));
	while (fgets(buffer, 5511, fin)) {
		ok = 0;
		//printf("%s",buffer);
		soltask1(buffer, &ok);
		verifstrcmp(buffer, &ok);
		fprintf(fout, "%d\n", ok);
	}

	if (buffer)
		free(buffer);
	///task2

	fclose(fout);
	fclose(fin);
}


///--------------SUBPROGRAME TASK2:-------------////

void verifff(char *buffer, int *ok)
{
	//printf("%s",buffer);
	char *string;
	string = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	//proiectie = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	//verif = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

	strcpy(string, buffer);
	char sep[] = ",";
	char *p = strtok(string, sep);

	//strcpy(verif, p);

	//int semafor = 0;
	int num = 1;
	//int payload = 0;
	//---
	int t = 0;
	while (p) {
		if (num == 4) {
			//printf("r%sr\n",p);
			if (strcmp(p, "443") == 0)
				t = 1;
				//printf("r%sr\n",p);
			//printf("%s\n",p);
			if (strcmp(p, "1947") == 0)
				t = 1;
			if (strcmp(p, "137") == 0)
				t = 1;
			//if (strcmp(p, "3306") == 0)
				//*ok = 1;
			//if (strcmp(p, "58984") == 0)
				//*ok = 1;
			//if (strcmp(p, "50443") == 0)
				//*ok = 1;
		}
		p = strtok(NULL, sep);
		num++;
	}

	if (string)
		free(string);
}

void verificare(char *buffer, int *ok)
{
	//printf("%s",buffer);
	char *string;
	string = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	//proiectie = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	//verif = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

	strcpy(string, buffer);
	char sep[] = ",";
	char *p = strtok(string, sep);

	//strcpy(verif, p);

	//int semafor = 0;
	int num = 1;
	//int payload = 0;
	//---

	char *ip_first = strtok(string, ".");
	char *ip_second = strtok(NULL, ".");

	int t = 0;

	while (p) {
		if (num == 2) {
			char *repip_first = strtok(p, ".");
			char *repip_second = strtok(NULL, ".");

		//printf()
			if (*ip_first == *repip_first && *ip_second == *repip_second)
				t = 1;
		}
		if (num == 4) {
			if (strcmp(p, "138") == 0 && t == 1)
				*ok = 1;
				//printf("r%sr\n",p);
			//printf("%s\n",p);
			if (strcmp(p, "1947") == 0 && t == 1)
				*ok = 1;
			if (strcmp(p, "137") == 0 && t == 1)
				*ok = 1;
		}
		p = strtok(NULL, sep);
		num++;
	}
	if (string)
		free(string);
}

void verifflowdurat(char *buffer, int *ok)
{
	int t = 0;
	if (*ok == 0)
		t = 0;
	char sep[] = ",";
	char *verif;
	verif = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

	int num = 1;
	strcpy(verif, buffer);
	char *v = strtok(verif, sep);
	//printf("%s",buffer);
	while (v) {
		if (num == 3) {
			//if (strcmp(v, "184.0.48.169") == 0) { /// response_ip
				//*ok = 0;// e safe
				//printf("%s\n", v);
				//break;
			//}
			if (strcmp(v, "184.0.48.255") == 0) { /// response_ip
				*ok = 1;// e safe
				//printf("%s\n", v);
				//break;
			}
			if (strcmp(v, "255.255.255.255") == 0) { /// response_ip
				*ok = 0;// e safe
				//printf("%s\n", v);
				//break;
			}
		}
		if (num == 5 && t == 0) {
			///if (strstr(p, "00:00:02")) { ///daca e mai mare decat 00:00:01
				//printf("merge\n");
				//*ok = 1;
		///00:00:01 -> 8 caractere
			for (int j = 0; j <= 7; j++)
				verif[j] = v[j + 7];
			verif[8] = '\0';
			///printf("%s\n",verif);
			if (strcmp(verif, "00:00:01") >= 0) {
				printf("da\n");
				//*ok=1;
				//*ok = 1;
			}
		}
		v = strtok(NULL, sep);
		num++;
	}

	if (verif)
		free(verif);
}

void soltask2(char *buffer, int *ok)
{
	///recunoastem daca are la final .exe sau cv
	///verificam daca e in baza de date
	int semafor = 0;
	//verifflowdurat(buffer, &semafor);
	verificare(buffer, &semafor);
	verifff(buffer, &semafor);
	//verifflowdurat(buffer, &semafor);
	//verificare(buffer, &semafor);
	//verifff(buffer, &semafor);
	//verifFlowPay(buffer, &semafor);
	*ok = semafor;
}


void task2(void)
{
	FILE *fin, *fout;

	fout = fopen("traffic-predictions.out", "w");
	fin = fopen("data/traffic/traffic.in", "r");

	char *buffer = NULL;
	int ok;

	buffer = (char *)malloc(5511 * sizeof(char));
	fgets(buffer, 5511, fin);
	while (fgets(buffer, 5511, fin)) {
		ok = 0;
		//printf("%s",buffer);
		soltask2(buffer, &ok);
		fprintf(fout, "%d\n", ok);
		///printf("%s",buffer);
	}

	if (buffer)
		free(buffer);

	fclose(fout);
	fclose(fin);
}

void task3(void)
{
	FILE *fin, *fout, *fins;

	fout = fopen("urls-predictions.out", "r");
	fin = fopen("REF1.ref", "r");
	fins = fopen("data/urls/urls.in", "r");

	char *buffer = NULL;

	buffer = (char *)malloc(5511 * sizeof(char));

	char *bufferaux = NULL;

	int NR = 0;
	bufferaux = (char *)malloc(5511 * sizeof(char));

	char *bufferauxy = NULL;

	bufferauxy = (char *)malloc(5511 * sizeof(char));

	int varb = 0;
	// buffer -> REF    fin
	// bufferaux -> OUTPUT   fout
	// bufferauxy -> urls   fis
	while (fgets(buffer, 5511, fin) && fgets(bufferaux, 5511, fout) &&
		   fgets(bufferauxy, 5511, fins)) { //coding deci comentez
		NR++;
		//printf("% %ss",buffer);
		// toate care au 0 in ref si 1 in predicitia mea
		/*if (strcmp(buffer, "0\n") == 0)
			if (strcmp(bufferaux, "1\n") == 0) {
				// nu.s egali ref are 1 celalat nu ia si newline aparent
				printf("%d %s", NR, bufferauxy);
				varb++;*/
		// toate care au 1 in ref si 0 in predicitia mea
		/*if (strstr(bufferauxy, "co.uk")) { ///daca are facebook.com/
			varb++; /// dadca are co.uk sau .com doa
			//r atat poate e safe si sa nu aiba
			/// alte punte dupa sau inainte
			printf("%d %s", NR, bufferauxy);
			//printf("%s",buffer);
		}*/
		if (strcmp(buffer, "0\n") == 0)
			//if (strstr(bufferauxy, "facebook.com")) {
			if (strcmp(bufferaux, "1\n") == 0) {
				// nu.s egali ref are 1 celalat nu ia si newline aparent
				printf("%d %s", NR, bufferauxy);
				varb++;
			//printf("%s",buffer);
		}
	}
	printf("\n%d\n", varb);

	if (buffer)
		free(buffer);
	if (bufferaux)
		free(bufferaux);
	if (bufferauxy)
		free(bufferauxy);

	fclose(fout);
	fclose(fin);
}

void task4(void)
{
	FILE *fin, *fout, *fins;

	fout = fopen("traffic.out", "r");
	fin = fopen("REF1.ref", "r");
	fins = fopen("data/urls/urls.in", "r");

	char *buffer = NULL;

	buffer = (char *)malloc(5511 * sizeof(char));

	char *bufferaux = NULL;

	int NR = 0;
	bufferaux = (char *)malloc(5511 * sizeof(char));

	char *bufferauxy = NULL;

	bufferauxy = (char *)malloc(5511 * sizeof(char));

	int varb = 0;
	// buffer -> REF    fin
	// bufferaux -> OUTPUT   fout
	// bufferauxy -> urls   fis
	while (fgets(buffer, 5511, fin) && fgets(bufferaux, 5511, fout) &&
		   fgets(bufferauxy, 5511, fins)) { //coding deci comentez
		NR++;
		//printf("% %ss",buffer);
		// toate care au 0 in ref si 1 in predicitia mea
		/*if (strcmp(buffer, "0\n") == 0)
			if (strcmp(bufferaux, "1\n") == 0) {
				// nu.s egali ref are 1 celalat nu ia si newline aparent
				printf("%d %s", NR, bufferauxy);
				varb++;*/
		// toate care au 1 in ref si 0 in predicitia mea
		/*if (strstr(bufferauxy, "co.uk")) { ///daca are facebook.com/
			varb++; /// dadca are co.uk sau .com doa
			//r atat poate e safe si sa nu aiba
			/// alte punte dupa sau inainte
			printf("%d %s", NR, bufferauxy);
			//printf("%s",buffer);
		}*/
		if (strcmp(buffer, "1\n") == 0)
			//if (strstr(bufferauxy, "facebook.com")) {
			if (strcmp(bufferaux, "0\n") == 0) {
				// nu.s egali ref are 1 celalat nu ia si newline aparent
				printf("%d %s", NR, bufferauxy);
				varb++;
			//printf("%s",buffer);
		}
	}
	printf("\n%d\n", varb);

	if (buffer)
		free(buffer);
	if (bufferaux)
		free(bufferaux);
	if (bufferauxy)
		free(bufferauxy);

	fclose(fout);
	fclose(fin);
	fclose(fins);
}

int main(void)
{
	task1();
	task2();
	task3();

	//printf("%d\n", global);
	///printf("%d\n",GLOBAL);
	return 0;
}
