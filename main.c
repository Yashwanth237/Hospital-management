/*This program is a Hospital Receptionist Management system. It is designed to help manage the data of patients, making it more useful and efficient for the receptionist.*/ 

//Header files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Patients max number :100
#define SIZE 100

// patients structure
struct patient {
    char name[100];
    int age;
    int bed_no;
    long long int pno;
    char address[100];
};

// Global Variables:

char username[100];
char password[100];
struct patient patients[SIZE];
int logged_in = 0;

// Functions which are used in this program
void display_menu();
void patient_details();
void check_details();
void update_details();
void display_signup();
void loading_animation();
void Exiting_animation();
void signup();
void login();
void takepassword(char *password);

//MAIN FUNCTION:
int main() {
    display_signup();
    int n;
label:
    printf("\n\t\t\tEnter the option: ");
    scanf("%d", &n);
    getchar();  // Clear newline character from buffer
    if (n == 1) {
        signup();
    } else if (n == 2) {
        login();
    } else {
        printf("\n\t\tEntered wrong option !!, Try again....");
        goto label;
    }

    if (logged_in) {
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
                    break;
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

// patient_details(), This Function helps to add the patient details and stores it in a patients.csv file 
void patient_details() {
    int num_patients;
    printf("\n\t\t\tHow many patients do you want to add: ");
    scanf("%d", &num_patients);
    getchar();

    FILE *ptr = fopen("Patients.csv", "a");
    if (ptr == NULL) {
        printf("\n\t\tFile could not open!!!.......");
        return;
    }

    printf("\n");
    for (int i = 0; i < num_patients; i++) {
        printf("\n\t\tEnter the Patient %d Details:\n", i + 1);
        printf("\n");
        printf("\n\t\tEnter the Patient Name: ");
        fgets(patients[i].name, sizeof(patients[i].name), stdin);
        strtok(patients[i].name, "\n");
        printf("\n\t\tEnter the Patient age: ");
        scanf("%d", &patients[i].age);
        printf("\n\t\tEnter the bed number of the patient: ");
        scanf("%d", &patients[i].bed_no);
        printf("\n\t\tEnter the phone number of the patient: ");
        scanf("%lld", &patients[i].pno);
        getchar();
        printf("\n\t\tEnter the Address of the patient: ");
        fgets(patients[i].address, sizeof(patients[i].address), stdin);
        strtok(patients[i].address, "\n");
        printf("\n");

        fprintf(ptr, "%s,%d,%d,%lld,%s\n", patients[i].name, patients[i].age, patients[i].bed_no, patients[i].pno, patients[i].address);
    }

    fclose(ptr);
    printf("\n\tThe Details are saved Successfully.......\n");
}

// check_details(), This Function helps toCheck the patient details in the patients.csv file 
void check_details() {
    int bed_no;
    printf("\n\t\tEnter the bed number to check the patient details: ");
    scanf("%d", &bed_no);
    getchar();

    FILE *ptr = fopen("Patients.csv", "r");
    if (ptr == NULL) {
        printf("\n\t\tFile could not open!!!.......");
        return;
    }

    int found = 0;
    while (fscanf(ptr, "%[^,],%d,%d,%lld,%[^\n]\n", patients[0].name, &patients[0].age, &patients[0].bed_no, &patients[0].pno, patients[0].address) != EOF) {
        if (bed_no == patients[0].bed_no) {
            printf("\nPatient name: %s\n", patients[0].name);
            printf("Patient Age: %d\n", patients[0].age);
            printf("Patient Bed number: %d\n", patients[0].bed_no);
            printf("Patient Phone number: %lld\n", patients[0].pno);
            printf("Patient Address: %s\n", patients[0].address);
            found = 1;
            break;
        }
    }

    fclose(ptr);
    if (!found) {
        printf("\n\t\tNo patient found with bed number %d\n", bed_no);
    }
}

// update_details(), This Function helps to Update the patient details and stores in the patients.csv file 
void update_details() {
    int bed_no;
    char op;

    printf("\t\tEnter the bed number to check and update the patient details: ");
    scanf("%d", &bed_no);
    getchar();

    FILE *ptr = fopen("Patients.csv", "r");
    if (ptr == NULL) {
        printf("\n\t\tFile could not open!!!.......");
        return;
    }

    int found = 0;
    int i = 0;

    // Read each line of the file
    while (fscanf(ptr, "%[^,],%d,%d,%lld,%[^\n]\n", patients[i].name, &patients[i].age, &patients[i].bed_no, &patients[i].pno, patients[i].address) != EOF) {
        if (bed_no == patients[i].bed_no) {
            found = 1;
            printf("\n\t\tPatient name: %s", patients[i].name);
            printf("\n\t\tPatient Age: %d", patients[i].age);
            printf("\n\t\tPatient Bed number: %d", patients[i].bed_no);
            printf("\n\t\tPatient Phone number: %lld", patients[i].pno);
            printf("\n\t\tPatient Address: %s", patients[i].address);

            printf("\n\nAre these the patient details you want to update (Y/N)? ");
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
            } else if (op == 'N' || op == 'n') {
                printf("Rechecking details...\n");
                i = -1; // Restart the loop
            } else {
                printf("\t\t\tYou entered an invalid option.\n");
            }
        }
        i++;
    }
    fclose(ptr);

    if (!found) {
        printf("\n\t\t\tNo patient found with bed number %d\n", bed_no);
    } else {
        // Write updated details back to the file
        FILE *write_ptr = fopen("Patients.csv", "w");
        if (write_ptr == NULL) {
            printf("\n\t\tFile could not open for writing!!!.......");
            return;
        }

        for (int j = 0; j < i; j++) {
            fprintf(write_ptr, "%s,%d,%d,%lld,%s\n", patients[j].name, patients[j].age, patients[j].bed_no, patients[j].pno, patients[j].address);
        }
        fclose(write_ptr);
    }
}

//display_signup(),This function shows the menu page
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

//loading_animation(), this is a loading animation 
void loading_animation() {
    char loading[15] = {'L', 'o', 'a', 'd', 'i', 'n', 'g', '.', '.', '.', '.'};
    for (int i = 0; i < 3; i++) {
        printf("\r------------------\r");
        for (int j = 0; j <= 8; j++) {
            printf("%c ", loading[j]);
            usleep(100000);
        }
    }
    printf("\r                    \r");
}

//Exiting_animation(), this is a Exiting animation 
void Exiting_animation() {
    char loading[15] = {'E', 'x', 'i', 't', 'i', 'n', 'g', '.', '.', '.', '.'};
    for (int i = 0; i < 3; i++) {
        printf("\r------------------\r");
        for (int j = 0; j <= 8; j++) {
            printf("%c ", loading[j]);
            usleep(100000);
        }
    }
    printf("\r                    \r");
}
//signup(),This function is used to take user name and password from the consule page and stores the user name and password in "users.csv"
void signup() {
    printf("\n\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\n\t\t\tEnter password: ");
    takepassword(password);

    FILE *file = fopen("users.csv", "a");
    if (file == NULL) {
        printf("\t\t\tCould not open file %s for writing.\n", "users.csv");
        exit(1);
    }

    fprintf(file, "%s,%s\n", username, password);
    fclose(file);

    printf("\t\t\tSignup successful\n");
    printf("\n\t\tPress Enter for registration\n");
    getchar(); // Clear newline character from buffer
    login();
}

//login(),This function is used to take user name and password from the consule page and compares the user name and password with signup deatils which stroed in ( "users.csv")
void login() {
    char file_username[100], file_password[100];
    char doc_user_name[100] = "IIES";
    char doc_user_password[100] = "9949";
    char opt[100];

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

    printf("\n\n\tEnter the valid option: ");
    scanf("%s", opt);
    if (opt[0] == '1') {
        printf("\n\t\tEnter username: ");
        scanf("%s", username);
        printf("\n\t\tEnter password: ");
        takepassword(password);

        FILE *file = fopen("users.csv", "r");
        if (file == NULL) {
            printf("Could not open file.\n");
            exit(1);
        }

        logged_in = 0;
        while (fscanf(file, "%[^,],%s\n", file_username, file_password) != EOF) {
            if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
                logged_in = 1;
                break;
            }
        }
        fclose(file);

        if (logged_in) {
            printf("\n\t\tLogin successful!\n");
        } else {
            printf("\n\t\tInvalid username or password. Try again.\n");
            goto log;
        }
    } else if (opt[0] == '2') {
        printf("\n\t\tEnter DOCTOR Name: ");
        scanf("%s", username);
        printf("\n\t\tEnter DOCTOR Password: ");
        scanf("%s", password);

        if (strcmp(username, doc_user_name) == 0 && strcmp(password, doc_user_password) == 0) {
            int cho;
            while (1) {
                printf("\n\t\t1. CHECK THE PATIENT DETAILS");
                printf("\n\t\t2. UPDATE PATIENT DETAILS");
                printf("\n\t\t3. EXIT");
                printf("\n\n\t\tEnter your option: ");
                scanf("%d", &cho);

                switch (cho) {
                    case 1:
                        printf("\n\t\tGoing to check the patient details:\n");
                        loading_animation();
                        check_details();
                        break;
                    case 2:
                        printf("\n\t\tGoing to update the patient details:\n");
                        loading_animation();
                        update_details();
                        break;
                    case 3:
                        Exiting_animation();
                        printf("\n\t\tExited Successfully.....\n");
                        exit(0);
                    default:
                        printf("\n\t\tEnter a valid option!\n");
                }
            }
        } else {
            printf("\n\t\tInvalid doctor name or password. Try again.\n");
            goto log;
        }
    } else {
        printf("\n\n\t\tEnter a valid option!\n");
        fflush(stdin);
        printf("\n\t\tPress any key to view the login menu...");
        getchar();
        goto log;
    }
}

// this function is used to print * While taking password.
void takepassword(char *password) {
    int i = 0;
    char ch;
    while (1) {
        ch = getch();
        if (ch == 13) {
            password[i] = '\0';
            break;
        } else if (ch == 8) {  // backspace
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else if (ch == 9 || ch == 32) {  // Tab or Space
            continue;
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    printf("\n");
}

// this Function displays the the menu of the program.
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


// In this function there are several deaseses and its medicans are there, according to there deaseses they have to choose.

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

//Feedback(), Function is used to take the feedback from the user about the service of the hospital.

void feedback()
{

    FILE *ptr;
    ptr =fopen("Feedback.doc","a");

    if (ptr!=NULL){
            char feedback[2000];
            printf("\t\t\tEnter the Feedback: ");
            fgets(feedback,sizeof(feedback),stdin);
            fflush(stdin);
        fprintf(ptr,"\t\t\tFeedback: %s\n",feedback);
    }else{
    printf("\t\t\tFile could not opened successfully");
    }

}
