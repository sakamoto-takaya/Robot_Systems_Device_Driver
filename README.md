# やりたかったこと

英数字の文字列を入力すると、その文字列のモールス信号をLEDで表す。
英数字以外が表記されると点滅する

# できたこと




# 環境 



# 実行方法

$ git clone https://github.com/sakamoto-takaya/Robot_Systems_Device_Driver.git //リポジトリのクローン \n
$ cd Robot_Systems_Device_Driver  //リポジトリの移動 \n 
$ make //makeする \n
$ sudo insmod myled.ko  \n
$ sudo mknod /dev/myled0 c 507 0 \n
$ sudo chmod 666 /dev/myled0 \n
$ echo 文字 > /dev/myled0 //文字を打ち込むとモールスを3回光らせる \n
.
.
.
$ sudo rm /dev/myled0 \n
$ sudo rmmod myled //後処理 \n
 

# 結果 


# 動画 
