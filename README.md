# やりたいこと 

英数字の文字列を入力すると、その文字列のモールス信号をLEDで表す。
英数字以外が表記されると点滅する

# 環境 



# 実行方法

$ git clone https://github.com/sakamoto-takaya/Robot_Systems_Device_Driver.git

$ cd Robot_Systems_Device_Driver

$ make

$ sudo insmod myled.ko

$ sudo mknod /dev/myled0 c 507 0


# 結果 


# 動画 
