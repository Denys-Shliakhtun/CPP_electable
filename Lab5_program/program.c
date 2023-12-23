#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/factorial"

int main() {
    int fd;
    char write_buf[100];

    // Відкриваємо пристрій для зчитування/запису
    fd = open(DEVICE_PATH, O_RDWR);

    if (fd < 0) {
        printf("Не вдалося відкрити пристрій.\n");
        return -1;
    }

    printf("Введіть число для обчислення факторіалу: ");
    int num;
    scanf("%d", &num);

    // Формуємо команду для виклику
    sprintf(write_buf, "w%d", num);

    // Викликаємо системний виклик, щоб обчислити факторіал числа
    num = write(fd, write_buf, strlen(write_buf));

    printf("Результат: %d\n", num);

    // Закриваємо файловий дескриптор
    close(fd);

    return 0;
}
