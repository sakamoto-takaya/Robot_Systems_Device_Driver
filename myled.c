#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>　
#include <linux/delay.h>

MODULE_AUTHOR("Takaya Sakamoto and Ryuichi Ueda");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL v3 Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;

static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos){
 char c; //c[10];
 int i = 0;
 int j = 0;

 if(copy_from_user(&c,buf,sizeof(char))) 
  return -EFAULT;

 if (('a'<= c && c <='z') ||('A'<= c && c <='Z')||('0'<= c && c <='9')){
  for(i=0; i < 3; i++){
   if(c == 'a' || c == 'A'){             //・ー
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'b' || c == 'B'){     //ー・・・
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'c' || c == 'C'){     //ー・－・
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'd' || c == 'D'){     //ー・・
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'e' || c == 'E'){     //・
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'f' || c == 'F'){     //・・－・
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'g' || c == 'G'){     //ーー・
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'h' || c == 'H'){     //・・・・
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'i' || c == 'I'){//・・
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'j' || c == 'J'){     //・－－－
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'k' || c == 'K'){     //ー・－
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'l' || c == 'L'){     //・－・・
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'm' || c == 'M'){     //ーー
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'n' || c == 'N'){     //ー・
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'o' || c == 'O'){     //ーーー
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'p' || c == 'P'){     //・－－・
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'q' || c == 'Q'){     //ーー・－
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'r' || c == 'R'){     //・－・
    
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 's' || c == 'S'){     //・・・
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 't' || c == 'T'){     //ー
    
    gpio_base[7] = 1 << 25;
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'u' || c == 'U'){     //・・－
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'v' || c == 'V'){//・・・－
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'w' || c == 'W'){     //・－－
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'x' || c == 'X'){     //ー・・－
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == 'y' || c == 'Y'){     //ー・－－
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == 'z' || c == 'Z'){//ーー・・
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == '1'){//・－－－－
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == '2'){                 //・・－－－
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   } else if (c == '3'){                 //・・・－－
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == '4'){                 //・・・・－
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == '5'){                 //・・・・・
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == '6'){                 //ー・・・・
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・ 
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == '7'){                 //ーー・・・
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == '8'){//ーーー・・
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == '9'){//ーーーー・
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600); 
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー 
    msleep(600);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //・
    msleep(200);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
   } else if (c == '0'){//ーーーーー
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600); 
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25;
    msleep(200);
    
    gpio_base[7] = 1 << 25;              //ー
    msleep(600);
    gpio_base[10] = 1 << 25; 
    msleep(200);
    
   }
   gpio_base[10] = 1 << 25;
   msleep(1000);
   
  }
 } 
 return 1;
}

static struct file_operations led_fops = {
 .owner = THIS_MODULE,
 .write = led_write
};

static int __init init_mod(void){
 
 gpio_base = ioremap_nocache(0xfe200000, 0xA0);
 const u32 led = 25;
 const u32 index = led/10;
 const u32 shift = (led%10)*3;
 const u32 mask = ~(0x7 << shift);
 gpio_base[index] = (gpio_base[index] & mask) | (0x1 << shift);
 
 int retval;
 retval =  alloc_chrdev_region(&dev, 0, 1, "myled");
 
 if(retval < 0){
  printk(KERN_ERR "alloc_chrdev_region failed.\n");
  return retval;
 }
 
 printk(KERN_INFO "%s is loaded. major:%d\n",__FILE__,MAJOR(dev));

 cdev_init(&cdv, &led_fops);
 retval = cdev_add(&cdv, dev, 1);
 
 if(retval < 0){
  printk(KERN_ERR "cdev_add failed. major:%d, minor:%d",MAJOR(dev),MINOR(dev));
  return retval;
}
 
 cls = class_create(THIS_MODULE,"myled");
 
 if(IS_ERR(cls)){
  printk(KERN_ERR "class_create failed.");
  return PTR_ERR(cls);
 }
 
 device_create(cls, NULL, dev, NULL, "myled%d",MINOR(dev));
 
 return 0;
}


static void __exit cleanup_mod(void){
 cdev_del(&cdv);
 device_destroy(cls, dev);
 class_destroy(cls);
 unregister_chrdev_region(dev, 1);
 printk(KERN_INFO "%s is unloaded. major:%d\n",__FILE__,MAJOR(dev));
 iounmap(gpio_base);
}

module_init(init_mod);
module_exit(cleanup_mod);
