#include <stdio.h>
#include <string.h>

void signin(char[],char[],char[]);
void reset(char[],char[],char[],char[],char[],char[]);
void printPass();
void remKeys();

int main( int argc,char *argv[]){

    char sucretUserName[25];
    char sucrtPass[25];

    char discription[60];
    char discriptionLogs[60] = "discription: ";

    char user[44];
    char username[44] = "\nusername/email: ";

    char pass[44];
    char password[44] = "password: ";


    printf("Login name: ");
    scanf("%s",&sucretUserName);
    printf("Login pass: ");
    scanf("%s",&sucrtPass);

    // put your special username and your unique password in the if statement below.
    // the default username is "USER" & the default password is "PASSWORD".


    if(strcmp(sucretUserName,"USER") == 0 && strcmp(sucrtPass,"PASSWORD") == 0 ){
        
        int choise;

        while (choise != 3){

        printf("\n\nremove keys {0} See keys {1} Write keys {2} exit {3}: ");
        scanf("%d",&choise);

            if(choise == 2 ){

                printf("\nusername/email: ");
                scanf("%s",&user);
                printf("password: ");
                scanf("%s",&pass);

                strcat(username,user);
                strcat(username,"\n");
                strcat(password,pass);
                strcat(password,"\n");

                printf("Discription: ");
                scanf("%s",&discription);
                strcat(discriptionLogs,discription);

                signin(username, password,discriptionLogs);
                reset(discription,discriptionLogs,user,username,pass,password);

            }else if(choise==1){
                printPass();
            }else if(choise == 0){
                remKeys();
            }else{
                break;
            }
        }
        


    }else{
        printf("fuck off");
    }


    return 0;
}

void signin(char user[],char pass[],char dscrption[]){
    FILE *fP = fopen("C:\\Users\\SBS\\AppData\\Roaming\\keyKeeper\\keys.txt","a");
    fprintf(fP,user);  
    fprintf(fP,pass);
    fprintf(fP,dscrption);
    fprintf(fP,"\n################################");
    fclose(fP);
};

void printPass(){
    FILE *fP = fopen("C:\\Users\\SBS\\AppData\\Roaming\\keyKeeper\\keys.txt","r");
    char buffer[255];

    while (fgets(buffer,255,fP)!=NULL)
    {
        printf("%s ",buffer);
    };

    fclose(fP);

}

void remKeys(){
    FILE *fP = fopen("C:\\Users\\SBS\\AppData\\Roaming\\keyKeeper\\keys.txt","w");
    fprintf(fP,"");
    fclose(fP);
};

void reset(char dis[],char disLogs[],char user[],char userLog[],char pass[],char passLog[]){
    strcpy(dis,"");
    strcpy(disLogs,"discription: ");
    strcpy(user,"");
    strcpy(userLog,"\nusername/email: ");
    strcpy(pass,"");
    strcpy(passLog,"password: ");
};
