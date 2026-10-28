#include <stdio.h>

// Функц: Цельсийг Фаренгейт рүү хөрвүүлэх
float celsiusToFahrenheit(float c) {
    return (c * 9.0 / 5.0) + 32.0;
}

int main() {
    // 7 хоногийн өдрүүд (Англи эсвэл латин үсгээр гаргах нь компиляторт илүү найдвартай)
    const char *weekdays[7] = {"Davaa", "Myagmar", "Lkhagva", "Purev", "Baasan", "Byamba", "Nyam"};
    float temps[7];
    float min_temp;
    int min_index = 0;
    
    printf("--- OVIIN KHUITEN TOOTOI ---\n");

    for(int i = 0; i < 7; i++) {
        do {
            printf("%s garigiin temparaturiig (-50C-oos 20C hoorond) oruulna uu: ", weekdays[i]);
            scanf("%f", &temps[i]);
            if(temps[i] < -50 || temps[i] > 20) {
                printf("Aldaatai utga! Dahin oruulna uu.\n");
            }
        } while(temps[i] < -50 || temps[i] > 20);
    }

    printf("\n--- 7 HOGONII TEMPARATURIIN KHUSNEGT ---\n");
    printf("%-10s | %-10s | %-10s | %-20s\n", "Odriin ner", "Celsius", "Fahrenheit", "Angilal");
    printf("------------------------------------------------------------------\n");

    min_temp = temps[0];

    for(int i = 0; i < 7; i++) {
        float f = celsiusToFahrenheit(temps[i]);
        char *status;

        if (temps[i] <= -25) {
            status = "Tas khuiten";
        } else if (temps[i] <= -10) {
            status = "Khuiten";
        } else {
            status = "Dulaakhan";
        }

        printf("%-10s | %10.2f | %10.2f | %-20s\n", weekdays[i], temps[i], f, status);

        // Хамгийн хүйтэн өдрийг хайх
        if (temps[i] < min_temp) {
            min_temp = temps[i];
            min_index = i;
        }
    }

    printf("------------------------------------------------------------------\n");
    printf("Hamgiin khuiten odor: %s (%6.2f C)\n", weekdays[min_index], min_temp);

    return 0;
}