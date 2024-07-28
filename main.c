#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct patient {
    char name[100];
    int age;
    int bed_no;
    long long int pno;
    char address[100];
};


char username[100];
char password[100];
struct patient patients[SIZE];
int logged_in = 0;

void display_menu();
void patient_details();
void check_details();
void update_details();
void display_signup();
void loading_animation();
void Exiting_animation();
void signup();
void login();

int main() {

    display_signup();
    int n;
    label:
            printf("\n\t\t\tEnter the option: ");
            scanf("%d",&n);
            if(n==1)
            {
                signup();
            }
            else if(n==2)
            {
                login();
            }
            else
            {
            printf("\n\t\tEntered wrong option !!,Try again....");
            }

    if(logged_in){
        int continue_program = 1;

    while (continue_program) {
        display_menu();
        int option;
        printf("\n\t\tEnter the option: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                loading_animation();
                patient_details();
                break;
            case 2:
                loading_animation();
                check_details();
                break;
            case 3:
                loading_animation();
                update_details();
                break;
            case 4:
                loading_animation();
                check();
                break;
            case 5:
                loading_animation();
                feedback();
            case 6:
                Exiting_animation();
                printf("\n\t\tExited Successfully......");
                continue_program = 0;
                exit(0);
            default:
                printf("\n\t\t\tInvalid option! Please try again!!!.....\n");
        }

        if (continue_program) {
            char cont;
            printf("\n\t\tDo you want to continue (Y/N)? ");
            scanf(" %c", &cont);
            getchar();

            if (cont != 'Y' && cont != 'y') {
                continue_program = 0;
            }
        }
    }
}


    return 0;
}

void display_menu() {
    printf("\n\n\n");
    printf("\t\t\t*****************************************************\n");
    printf("\t\t\t*****************************************************\n");
    printf("\t\t\t*****                                          ******\n");
    printf("\t\t\t*****                                          ******\n");
    printf("\t\t\t*****           **** MENU ****                 ******\n");
    printf("\t\t\t*****                                          ******\n");
    printf("\t\t\t*****      1. ENTER PATIENT DETAILS            ******\n");
    printf("\t\t\t*****      2. CHECK PATIENT DETAILS            ******\n");
    printf("\t\t\t*****      3. EDIT PATIENT DETAILS             ******\n");
    printf("\t\t\t*****      4. CHECK DISEASES AND MEDICINE      ******\n");
    printf("\t\t\t*****      5. FEEDBACK ON THE HOSPITAL         ******\n");
    printf("\t\t\t*****      6. EXIT                             ******\n");
    printf("\t\t\t*****                                          ******\n");
    printf("\t\t\t*****                                          ******\n");
    printf("\t\t\t*****************************************************\n");
    printf("\t\t\t*****************************************************\n");
    printf("\n\n");
}

//This Function is used to Take the details the details of the patient

void patient_details() {
    int num_patients;
    printf("\n\t\t\tHow many patients do you want to add: ");
    scanf("%d", &num_patients);

    getchar();

    printf("\n");
    for (int i = 0; i < num_patients; i++) {
        printf("\n\t\tEnter the Patient %d Details:\n", i + 1);
        printf("\n\t\tEnter the Patient Name: ");
        fgets(patients[i].name, sizeof(patients[i].name), stdin);
        printf("\n\t\tEnter the Patient age: ");
        scanf("%d", &patients[i].age);
        printf("\n\t\tEnter the bed number of the patient: ");
        scanf("%d", &patients[i].bed_no);
        printf("\n\t\tEnter the phone number of the patient: ");
        scanf("%lld", &patients[i].pno);
        getchar();
        printf("\n\t\tEnter the Address of the patient: ");
        fgets(patients[i].address, sizeof(patients[i].address), stdin);
        printf("\n\n");
    }
    printf("\n\tThe Details are saved Successfully.......\n");
}

//This Function is used to Check the details of the patient stored in structure

void check_details() {
    int bed_no;
    printf("\n\t\tEnter the bed number to check the patient details: ");
    scanf("%d", &bed_no);
    getchar();


    for (int i = 0; i < SIZE; i++) {
        if (bed_no == patients[i].bed_no) {
            printf("\nPatient name: %s\n", patients[i].name);
            printf("Patient Age: %d\n", patients[i].age);
            printf("Patient Bed number: %d\n", patients[i].bed_no);
            printf("Patient Phone number: %lld\n", patients[i].pno);
            printf("Patient Address: %s\n", patients[i].address);
            return;
        }
    }
    printf("\n\t\tNo patient found with bed number %d\n", bed_no);
}

//This function is for update the patient details which stored in structure

void update_details() {
    int bed_no;
    char op;

    printf("\t\tEnter the bed number to check and update the patient details: ");
    scanf("%d", &bed_no);
    getchar();
    //clear_input_buffer(); // Clear input buffer after reading an integer

    for (int i = 0; i < SIZE; i++) {
        if (bed_no == patients[i].bed_no) {
                printf("\n");

            printf("\n\t\tPatient name: %s", patients[i].name);
            printf("\n\t\tPatient Age: %d", patients[i].age);
            printf("\n\t\tPatient Bed number: %d", patients[i].bed_no);
            printf("\n\t\tPatient Phone number: %lld", patients[i].pno);
            printf("\n\t\tPatient Address: %s", patients[i].address);

            printf("Are these details are correct (Y/N)? ");
            scanf(" %c", &op);
            getchar();

            if (op == 'Y' || op == 'y') {
                printf("Enter the Patient new Name: ");
                fgets(patients[i].name, sizeof(patients[i].name), stdin);
                printf("Enter the Patient new age: ");
                scanf("%d", &patients[i].age);
                printf("Enter the new phone number of the patient: ");
                scanf("%lld", &patients[i].pno);
                getchar();
                printf("Enter the new Address of the patient: ");
                fgets(patients[i].address, sizeof(patients[i].address), stdin);
                printf("Details updated successfully.\n");
                return;
            } else if (op == 'N' || op == 'n') {
                printf("Rechecking details...\n");
                i = -1; // Restart the loop
            } else {
                printf("\t\t\tYou entered an invalid option.\n");
            }
        }
    }
    printf("\n\t\t\tNo patient found with bed number %d\n", bed_no);
}

// Display Menu(login,signup,exit):

void display_signup() {
    printf("\n\n\n");
    printf("\t\t\t************************************************\n");
    printf("\t\t\t************************************************\n");
    printf("\t\t\t*****                                     ******\n");
    printf("\t\t\t*****                                     ******\n");
    printf("\t\t\t*****            **** MENU ****           ******\n");
    printf("\t\t\t*****                                     ******\n");
    printf("\t\t\t*****              1. SIGNUP              ******\n");
    printf("\t\t\t*****              2. LOGIN               ******\n");
    printf("\t\t\t*****              3. EXIT                ******\n");
    printf("\t\t\t*****                                     ******\n");
    printf("\t\t\t*****                                     ******\n");
    printf("\t\t\t************************************************\n");
    printf("\t\t\t************************************************\n");
    printf("\n\n");
}

//Loading animation Function:

void loading_animation() {
    char loading[15] = {'L', 'o', 'a', 'd', 'i', 'n', 'g', '.', '.', '.', '.'};
    for(int i = 0; i < 3; i++) {
        printf("\r------------------\r");
        for(int j = 0; j <= 8; j++) {
            printf("%c ", loading[j]);
            usleep(100000);
        }
    }
    printf("\r                    \r");
}

//Exiting animattion function:

void Exiting_animation() {
    char loading[15] = {'E', 'x', 'i', 't', 'i', 'n', 'g', '.', '.', '.', '.'};
    for(int i = 0; i < 3; i++) {
        printf("\r------------------\r");
        for(int j = 0; j <= 8; j++) {
            printf("%c ", loading[j]);
            usleep(100000);
        }
    }
    printf("\r                    \r");
}

//Signup function:

void signup() {
    char username[100];
    char password[100];
    printf("\n\t\t\tEnter username: ");
    fflush(stdin);
    scanf("%s", username);
    printf("\n\t\t\tEnter password: ");
    fflush(stdin);
    scanf("%s", password);

    FILE *file = fopen("users.csv", "a");
    if (file == NULL) {
        printf("\t\t\tCould not open file %s for writing.\n", "users.csv");
        exit(1);
    }

    fprintf(file, "%s,%s\n", username, password);
    fclose(file);

    printf("\t\t\tSignup successful\n");
    printf("\n\t\tPress Enter for registration\n");
    printf("\n");
    getch();
    login();
}

// Login function :

void login()
{
    char file_username[100], file_password[100];
    char doc_user_name[100]="IIES";
    char opt[100];
    char doc_user_password[100]= "9949";
    log:
    printf("\t\t\t******************************************\n");
    printf("\t\t\t******************************************\n");
    printf("\t\t\t*****                               ******\n");
    printf("\t\t\t*****     **** LOGIN ****           ******\n");
    printf("\t\t\t*****                               ******\n");
    printf("\t\t\t*****     1. USER LOGIN             ******\n");
    printf("\t\t\t*****     2. DOCTOR LOGIN           ******\n");
    printf("\t\t\t*****                               ******\n");
    printf("\t\t\t******************************************\n");
    printf("\t\t\t******************************************\n");

    printf("\n\n\tEnter the valid option : ");
    scanf("%s",&opt);
    if(opt[0]=='1')
    {
        printf("\n\t\tEnter username: ");
        scanf("%s", username);
        printf("\n\t\tEnter password: ");
        takepassword(password);

        FILE *file = fopen("users.csv", "r");
        if (file == NULL)
        {
            printf("Could not open file.\n");
            exit(1);
        }

        logged_in = 0;
        while (fscanf(file, "%[^,],%s\n", file_username, file_password) != EOF)
        {
            if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0)
            {
                logged_in = 1;
                break;
            }
        }
        fclose(file);
    }
    else if(opt[0]=='2')
    {
        printf("\n\t\tEnter DOCTOR Name: ");
        scanf("%s", username);
        printf("\n\t\tEnter DOCTOR Password: ");
        scanf("%s", password);
        if(strcmp(username,doc_user_name)==0 && strcmp(password, doc_user_password) == 0)
        {
            printf("1. CHECK THE PATIENT DETAILS\n2. UPDATE PATIENT DETAILS\n3. EXIT");
            int cho;
            printf("\n\t\tEnter your option");
            scanf("%d",&cho);
            switch(cho)
            {
            case 1:
                printf("\t\t\tGoing to check the patient details: \n");
                printf("\n");
                loading_animation();
                check_details();
                break;
            case 2:
                printf("\t\t\tGoing to Update the Patient details: \n");
                loading_animation();
                update_details();
                break;
            case 3:
                Exiting_animation();
                printf("\t\t\tExited Successfully.....");
                exit(0);
            default:printf("\t\t\tEnter the valid option !!!!.....");

            }
            getch();
        }
    }
    else
    {
        printf("\n\n\t\t\tEnter Valid Option !!!!....... ");
        fflush(stdin);
        printf("\n\t\tPress any Key to View Login Menu");
        getch();
        goto log;
    }
}

//Take the Password and Print *
void takepassword(char password[20])
{
    int i=0;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch==13){
            password[i]='\0';
            break;
        }
        else if(ch==8)   //backslash
        {
            if(i>0)
            {
                i--;
                printf("\b\b");
            }
        }
        else if(ch==9||ch==32){  //Space || Tab
            continue;
        }
        else{
            password[i++]=ch;
            printf("*");
        }
    }
    printf("\n");
}

// Feedback for the services:

void feedback()
{

    FILE *ptr;
    ptr =fopen("Feedback.doc","a");

    if (ptr!=NULL){
            char feedback[2000];
            printf("\t\t\tEnter the Feedback: ");
            fgets(feedback,sizeof(feedback),stdin);
        fprintf(ptr,"\t\t\tFeedback for the hospital: %s\n",feedback);
    }else{
    printf("\t\t\tFile could not opened successfully");
    }

}

//Check Function for deaseses:

void check() {

    printf("\n\n");
    printf("\t\t\t*************************************************\n");
    printf("\t\t\t*************************************************\n");
    printf("\t\t\t*****                                      ******\n");
    printf("\t\t\t*****                                      ******\n");
    printf("\t\t\t*****       ****** DEASESES ******         ******\n");
    printf("\t\t\t*****                                      ******\n");
    printf("\t\t\t*****      1. COUGH                        ******\n");
    printf("\t\t\t*****      2. DIABETES                     ******\n");
    printf("\t\t\t*****      3. TUBERCULOSIS (TB)            ******\n");
    printf("\t\t\t*****      4. HYPER TENSION                ******\n");
    printf("\t\t\t*****      5. FEVER                        ******\n");
    printf("\t\t\t*****      6. VITAMIN DEFICIENCY           ******\n");
    printf("\t\t\t*****      7. KIDNEY DISEASES              ******\n");
    printf("\t\t\t*****      8. EYE SIGHT                    ******\n");
    printf("\t\t\t*****      9. JOINT PAINS                  ******\n");
    printf("\t\t\t*****      10. DIGESTIVE PROBLEM           ******\n");
    printf("\t\t\t*****                                      ******\n");
    printf("\t\t\t*****                                      ******\n");
    printf("\t\t\t*************************************************\n");
    printf("\t\t\t*************************************************\n");



    printf("\n\n");

    int option;
    a:
    printf("Select the Disease: ");
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("\t\t\t************** COUGH ****************\n");
            printf("\n");
            printf("\t\t\tThere are two types of cough: \n");
            printf("\n");
            printf("\t\t\t 1) Dry cough\n");
            printf("\n");
            printf("\t\t\t 2) Wet cough\n");
            int cough;
            b:
            printf("Enter the option you want: ");
            scanf("%d", &cough);
            switch(cough) {
                case 1:
                    printf("\n\t\t\t\t************** Dry cough *************\n");
                    printf("\n");
                    printf("\t\t\tFor dry cough we have to use: DEXTROMETHORPHAN HYDROBROMIDE MONO HYDRATE 10MG\n");
                    printf("\n");
                    printf("\t\t\tMedicine Duration: 6-7 days\n");
                    printf("\n");
                    printf("\t\t\tUSE: 3 times in a day\n");
                    break;
                case 2:
                    printf("\n\t\t\t************* Wet cough **************\n");
                    printf("\n");
                    printf("\t\t\tFor wet cough we have to use: AMBROXOL HYDROCHLORIDE\n");
                    printf("\n");
                    printf("\t\t\tMedicine Duration: 6-7 days\n");
                    printf("\n");
                    printf("\t\t\tUSE: 3 times in a day\n");
                    break;
                default:
                    printf("\t !! Wrong Option !!\n");
                    goto b;
            }
            break;
        case 2:
            printf("\n\t\t\t\t************** DIABETES *************\n");
            printf("\n");
            printf("\t\tThere are 7 types of diabetes, in that there are majorly two types:\n");
            printf("\n");
            printf("\t\t\t 1) Type 1 diabetes\n");
            printf("\n");
            printf("\t\t\t 2) Type 2 diabetes\n");
            int diabetes;
            c:
            printf("\t\t\tEnter the option you want: ");
            scanf("%d", &diabetes);
            switch(diabetes) {
                case 1:
                    printf("\n\t\t\t\t************* Type 1 diabetes ************\n");
                    printf("\n");
                    printf("\t\t\tFor Type 1 diabetes we have to use: \n\t\t\t1) INSULIN\n\t\t\t2) DIETARY SUPPLEMENT\n\t\t\t3) HORMONE\n");
                    printf("\n");
                    printf("\t\t\tMedicine Duration: 6-12 months\n");
                    printf("\n");
                    printf("\t\t\tUSE: 3 times in a day before eating\n");
                    break;
                case 2:
                    printf("\n\t\t\t************ Type 2 diabetes ***********\n");
                    printf("\n");
                    printf("\t\t\tFor Type 2 diabetes we have to use: ANTI-DIABETIC MEDICATION\n");
                    printf("\n");
                    printf("\t\t\tMedicine Duration: 6-12 months\n");
                    printf("\n");
                    printf("\t\t\tUSE: 3 times in a day before eating\n");
                    break;
                default:
                    printf("\n\t !! Wrong Option !!\n");
                    goto c;
            }
            break;
        case 3:
            printf("\n\t\t\t************ TUBERCULOSIS (TB) ***********\n");
            printf("\n");
            printf("\t\t\tFor TUBERCULOSIS (TB) we have to use: ANTIBIOTICS\n");
            printf("\n");
            printf("\t\t\tMedicine Duration: 4-6 months\n");
            printf("\n");
            printf("\t\t\tUSE: 3 times in a day\n");
            break;
        case 4:
            printf("\n\t\t\t\t************ HYPER TENSION *************\n");
            printf("\n");
            printf("\n");
            printf("\t\t\tFor HYPER TENSION we have to use: \n\t\t\t1) VASODILATOR\n\t\t\t2) BETA BLOCKER\n\t\t\t3) DIURETIC\n");
            printf("\n");
            printf("\t\t\tMedicine Duration: 4 months\n");
            printf("\n");
            printf("\t\t\tUSE: Night times only\n");
            break;
        case 5:
            printf("\n\t\t\t\t****** FEVER ******\n");
            printf("\n");
            printf("\t\t\tThere are majorly two types:\n");
            printf("\n");
            printf("\t\t\t 1) MALARIA\n");
            printf("\n");
            printf("\t\t\t 2) DENGUE\n");
            int fever;
            d:
            printf("\t\t\tEnter the option you want: ");
            scanf("%d", &fever);
            switch(fever) {
                case 1:
                    printf("\n\t\t\t\t********* MALARIA **********\n");
                    printf("\n");
                    printf("\t\t\tFor MALARIA we have to use: \n\t\t\t1) ANTIPARASITIC\n\t\t\t2) ANTIBIOTICS\n");
                    printf("\n");
                    printf("\t\t\tMedicine Duration: 1-2 weeks\n");
                    printf("\n");
                    printf("\t\t\tUSE: 3 times in a day before eating\n");
                    break;
                case 2:
                    printf("\n\t\t\t\t********* DENGUE *********\n");
                    printf("\n");
                    printf("\t\t\tFor DENGUE we have to use: ANALGESIC\n");
                    printf("\n");
                    printf("\t\t\tMedicine Duration: 1-2 weeks\n");
                    printf("\n");
                    printf("\t\t\tUSE: 3 times in a day before eating\n");
                    break;
                default:
                    printf("\t\t\t\t !! Wrong Option !!\n");
                    goto d;
            }
            break;
        case 6:
            printf("\n\t\t\t\t********* VITAMIN DEFICIENCY *********\n");
            printf("\t\tFor VITAMIN DEFICIENCY we have to use: VITAMIN A, VITAMIN C, VITAMIN D\n");
            printf("\n");
            printf("\t\t\tMedicine Duration: 1-4 days\n");
            printf("\n");
            printf("\t\t\tUSE: Whenever it is required\n");
            break;
        case 7:
            printf("\n\t\t\t\t****** KIDNEY DISEASES ******\n");
            printf("\t\nFor KIDNEY DISEASES (CKD) CHRONIC KIDNEY DISEASES we have to use:\n1) BETA BLOCKERS\n2) GLP-1\n");
            printf("\n");
            printf("\t\t\tMedicine Duration: 6-7 months\n");
            printf("\n");
            printf("\t\t\tUSE: 3 times in a day before eating\n");
            break;
        case 8:
            printf("\n\t\t\t\t****** EYE SIGHT ******\n");
            printf("\n");
            printf("\t\t\tThere are 2 types in eye sight:\n");
            printf("\n");
            printf("\t\t\t 1) LONG SIGHT\n");
            printf("\n");
            printf("\t\t\t 2) SHORT SIGHT\n");
            int eye;
            e:
            printf("\t\t\tEnter the option you want: ");
            scanf("%d", &eye);
            switch(eye) {
                case 1:
                    printf("\n****** LONG SIGHT ******\n");
                    printf("\t\t\tFor LONG SIGHT we have to use: ANTIBIOTICS\n");
                    printf("\t\t\tMedicine Duration: 1-2 weeks\n");
                    printf("\t\t\tUSE: 3 times in a day before eating\n");
                    break;
                case 2:
                    printf("\n\t\t\t****** SHORT SIGHT ******\n");
                    printf("\n\t\t\tFor SHORT SIGHT we have to use: ANTIBIOTICS\n");
                    printf("\n\t\t\tMedicine Duration: 1-2 weeks\n");
                    printf("\n\t\t\tUSE: 3 times in a day before eating\n");
                    break;
                default:
                    printf("\t\t\t !! Wrong Option !!\n");
                    goto e;
            }
            break;
        case 9:
            printf("\n\t\t\t****** JOINT PAINS ******\n");
            printf("\n");
            printf("\t\t\tFor JOINT PAINS we have to use: NONSTEROIDAL ANTI-INFLAMMATORY DRUG\n");
            printf("\n");
            printf("\t\t\tMedicine Duration: 6 months\n");
            printf("\n");
            printf("\t\t\tUSE: 3 times in a day before eating\n");
            break;
        case 10:
            printf("\n\t\t\t****** DIGESTIVE PROBLEM ******\n");
            printf("\n");
            printf("\t\t\tFor DIGESTIVE PROBLEM we have to use: DIGENE TABLET, ANTIBIOTICS\n");
            printf("\n");
            printf("\t\t\tMedicine Duration: 3-4 days\n");
            printf("\n");
            printf("\t\t\tUSE: 2 times in a day before eating\n");
            break;
        default:
            printf("\t\t\t\t !! Wrong Option !! \n");
            goto a;
    }
}
