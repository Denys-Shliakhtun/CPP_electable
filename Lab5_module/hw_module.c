#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/init.h>

// Реалізувати write, який приймає ціле число і шукає його факторіал.

#define DEVICE_NAME "factorial"
#define BUF_LEN 80 

MODULE_AUTHOR("Denys Shliakhtun"); 
MODULE_DESCRIPTION("Lab1 test kernel module"); 
MODULE_LICENSE("MIT"); 

static int major;

int factorial(int num)
{
    if (num<=0 || num==1)
        return 1;

    return num * factorial(num-1);
}

static ssize_t device_write_fn(struct file *filp, const char *buff, size_t len, loff_t *off) 
{
    int num;
    char command;
    int result;
    
    // Зчитуємо команду з буфера
    get_user(command, buff);

    // Якщо команда - 'w', це запуск системного виклику
    if (command == 'w') {
        buff++;
        // Зчитуємо число з буфера
        if (kstrtoint(buff, 10, &num) != 0)
            return -EFAULT;

        // Обчислюємо факторіал числа
        result = factorial(num);

        // Повертаємо факторіал
        return result;
    }

    return -EINVAL; // Помилка неправильної команди
}

static struct file_operations fops = {
    .write = device_write_fn
};

static int __init hw_init(void)
{
    major = register_chrdev(0, DEVICE_NAME, &fops);

    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }

    printk(KERN_INFO "Factorial module has been loaded: %d\n", major);
    printk(KERN_INFO "Create a device with: mknod /dev/%s c %d 0\n", DEVICE_NAME, major);
    return 0;
}

static void __exit hw_exit(void)
{
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Factorial module has been unloaded\n");
}

module_init(hw_init);
module_exit(hw_exit);