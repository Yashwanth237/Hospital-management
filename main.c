//Header files:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Patient structure:
struct patient {
    char name[100];
    int age;
    int bed_no;
    long long int pno;
    char address[100];
};

// Global variable:
int logged_in = 0;

//FUNCTIONS:

void display_menu();
void display_signup();
void signup();
void login();
void save_patient_details(struct patient p[], int size);
int load_patient_details(struct patient p[]);
void take_details(struct patient p[], int size);
void check();
void menu();
void update_patient_details();
void loading_animation();
void takepassword(char password[20]);

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

void display_menu()
{
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
    printf("\t\t\t*****      4. CHECK DEASESES AND ITS MEDICAN   ******\n");
    printf("\t\t\t*****      5. FEEDBACK ON THE HOSPITAL         ******\n");
    printf("\t\t\t*****      6. EXIT                             ******\n");
    printf("\t\t\t*****                                          ******\n");
    printf("\t\t\t*****                                          ******\n");
    printf("\t\t\t*****************************************************\n");
    printf("\t\t\t*****************************************************\n");
    printf("\n\n");


}


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

int main() {
    system("color 70");
    printf("\n\n\t\t*********** WELCOME TO THE HOSPITAL MANAGEMENT SYSTEM **********\n\n");
    display();

    int option;
    struct patient patients[100];
    int patient_count = load_patient_details(patients);

    do {

        display_menu();
        system("color 70");
        printf("\t\t\tEnter the option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                loading_animation();
                patient_details(patients, &patient_count);
                save_patient_details(patients, patient_count);
                break;
            }
            case 2: {
                loading_animation();
                take_details(patients, patient_count);
                break;
            }
            case 3: {
                loading_animation();
                update_patient_details();
                break;
            }
            case 4: {
                loading_animation();
                check();
                break;
            }
            case 5:
                feedback();
                break;
            case 6:
                Exiting_animation();
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }

        char choice;
        printf("\nDo you want to continue? (y/n): ");
        getchar();
        choice = getchar();
        if (choice == 'n' || choice == 'N') {
            char loading[15] = {'L', 'o', 'a', 'd', 'i', 'n', 'g', '.', '.', '.', '.'};
            for(int i = 0; i < 3; i++) {
            printf("\r------------------\r");
            for(int j = 0; j <= 8; j++) {
            printf("%c ", loading[j]);
            usleep(100000);
        }
    }
    printf("\r                    \r");
            exit(0);
        }

    } while(option != 6);

    return 0;
}

void display() {
    int option;
    a:
    display_signup();
    printf("\t\t\tEnter the Option: ");
    scanf("%d", &option);
    switch(option) {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        default:
            printf("Invalid option\n");
            goto a;
    }
}

void signup() {
    char username[100];
    char password[100];
    printf("\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\t\t\tEnter password: ");
    scanf("%s", password);

    FILE *file = fopen("users.csv", "a");
    if (file == NULL) {
        printf("\t\t\tCould not open file %s for writing.\n", "users.csv");
        exit(1);
    }

    fprintf(file, "%s,%s\n", username, password);
    fclose(file);

    printf("\t\t\tSignup successful\n");
    exit(0);
}

void login() {
    char username[100];
    char password[100], file_username[100], file_password[100];
    printf("\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\t\t\tEnter password: ");
    takepassword(password);

    FILE *file = fopen("users.csv", "r");
    if (file == NULL) {
        printf("\t\t\tCould not open file.\n");
        exit(1);
    }

    while (fscanf(file, "%[^,],%s\n", file_username, file_password) != EOF) {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            logged_in = 1;
            break;
        }
    }
    fclose(file);

    if (logged_in) {
        printf("\t\t\tLogin successful\n");


    } else {
        printf("\t\t\tInvalid username or password\n");
        exit(1);
    }
}

void save_patient_details(struct patient p[], int size) {
    FILE *file = fopen("patients.txt", "w");
    if (file == NULL) {
        printf("\t\t\tCould not open file %s for writing.\n", "patients.txt");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s,%d,%d,%lld,%s\n", p[i].name, p[i].age, p[i].bed_no, p[i].pno, p[i].address);
    }

    fclose(file);
}

int load_patient_details(struct patient p[]) {
    FILE *file = fopen("patients.txt", "r");
    if (file == NULL) {
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%[^,],%d,%d,%lld,%[^\n]\n", p[count].name, &p[count].age, &p[count].bed_no, &p[count].pno, p[count].address) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

void patient_details(struct patient p[], int* size) {
    int count;
    system("color 70");
    printf("\t\t\tEnter the number of patients you want to add: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("\t\t\tEnter the patient name: ");
        getchar();
        fgets(p[*size].name, sizeof(p[*size].name), stdin);
        p[*size].name[strcspn(p[*size].name, "\n")] = '\0';

        printf("\t\t\tEnter the age of the patient: ");
        scanf("%d", &p[*size].age);
        printf("\t\t\tEnter the Bed number of the patient: ");
        scanf("%d", &p[*size].bed_no);
        printf("\t\t\tEnter the phone number of the patient: ");
        scanf("%lld", &p[*size].pno);
        printf("\t\t\tEnter the patient address: ");
        getchar();
        fgets(p[*size].address, sizeof(p[*size].address), stdin);
        p[*size].address[strcspn(p[*size].address, "\n")] = '\0';

        (*size)++;
    }
}

void take_details(struct patient p[], int size) {
    int option;
    printf("\t\t\tEnter the bed number to check: ");
    scanf("%d", &option);

    for (int i = 0; i < size; i++) {
        if (option == p[i].bed_no) {
            printf("\t\t\t\tPatient name: %s\n", p[i].name);
            printf("\t\t\t\tPatient age: %d\n", p[i].age);
            printf("\t\t\t\tPatient bed number: %d\n", p[i].bed_no);
            printf("\t\t\t\tPatient mobile number: %lld\n", p[i].pno);
            printf("\t\t\t\tPatient address: %s\n", p[i].address);
            return;
        }
    }
    printf("\t\t\tPatient with bed number %d not found.\n", option);
}

void update_patient_details() {
    FILE *file = fopen("patients.txt", "r+");
    if (file == NULL) {
        printf("\t\t\tCould not open file %s for reading and writing.\n", "patients.txt");
        exit(1);
    }

    struct patient p;
    int bed_no, found = 0;

    printf("\t\t\tEnter the bed number of the patient to update: ");
    scanf("%d", &bed_no);

    FILE *temp_file = fopen("temp.txt", "a");
    if (temp_file == NULL) {
        printf("\t\t\tCould not open temp file for writing.\n");
        exit(1);
    }

    while (fscanf(file, "%[^,],%d,%d,%lld,%[^\n]\n", p.name, &p.age, &p.bed_no, &p.pno, p.address) != EOF) {
        if (p.bed_no == bed_no) {
            found = 1;
            printf("\t\t\tEnter new details for bed number %d:\n", bed_no);
            printf("\n");
            printf("\t\t\tEnter the patient name: ");
            getchar();
            fgets(p.name, sizeof(p.name), stdin);
            p.name[strcspn(p.name, "\n")] = '\0';

            printf("\t\t\tEnter the age of the patient: ");
            scanf("%d", &p.age);
            printf("\t\t\tEnter the phone number of the patient: ");
            scanf("%lld", &p.pno);
            printf("\t\t\tEnter the patient address: ");
            getchar();
            fgets(p.address, sizeof(p.address), stdin);
            p.address[strcspn(p.address, "\n")] = '\0';
        }
        fprintf(temp_file, "%s,%d,%d,%lld,%s\n", p.name, p.age, p.bed_no, p.pno, p.address);
    }

    fclose(file);
    fclose(temp_file);

    if (!found) {
        printf("\t\t\tPatient with bed number %d not found.\n", bed_no);
    } else {
        remove("patients.txt");
        rename("temp.txt", "patients.txt");
        printf("\t\t\tPatient details updated successfully.\n");
    }
}

void check() {


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
                    printf("\t !! Wrong Option !!\n");
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
            printf("Enter the option you want: ");
            scanf("%d", &eye);
            switch(eye) {
                case 1:
                    printf("\n****** LONG SIGHT ******\n");
                    printf("\t\t\tFor LONG SIGHT we have to use: ANTIBIOTICS\n");
                    printf("\t\t\tMedicine Duration: 1-2 weeks\n");
                    printf("\t\t\tUSE: 3 times in a day before eating\n");
                    break;
                case 2:
                    printf("\n****** SHORT SIGHT ******\n");
                    printf("For SHORT SIGHT we have to use: ANTIBIOTICS\n");
                    printf("Medicine Duration: 1-2 weeks\n");
                    printf("USE: 3 times in a day before eating\n");
                    break;
                default:
                    printf("\t !! Wrong Option !!\n");
                    goto e;
            }
            break;
        case 9:
            printf("\n****** JOINT PAINS ******\n");
            printf("\n");
            printf("For JOINT PAINS we have to use: NONSTEROIDAL ANTI-INFLAMMATORY DRUG\n");
            printf("\n");
            printf("Medicine Duration: 6 months\n");
            printf("\n");
            printf("USE: 3 times in a day before eating\n");
            break;
        case 10:
            printf("\n****** DIGESTIVE PROBLEM ******\n");
            printf("\n");
            printf("For DIGESTIVE PROBLEM we have to use: DIGENE TABLET, ANTIBIOTICS\n");
            printf("\n");
            printf("Medicine Duration: 3-4 days\n");
            printf("\n");
            printf("USE: 2 times in a day before eating\n");
            break;
        default:
            printf("\t\t\t\t !! Wrong Option !! \n");
            goto a;
    }
}
void feedback()
{

    FILE *ptr;
    ptr =fopen("Feedback.doc","a");
    if (ptr!=NULL){
            char feedback[2000];
            printf("\t\t\tEnter the Feedback: ");
            fgets(feedback,sizeof(feedback),stdin);
        fprintf(ptr,"\t\t\tFeedback: %s\n",feedback);
    }else{
    printf("\t\t\tFile could not opened successfully");
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
