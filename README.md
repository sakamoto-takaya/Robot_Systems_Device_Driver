# やったこと

英数字の文字列を入力すると、その文字列のモールス信号をLEDで表す。 <br>

# 環境 

- Rasberry Pi 4 <br>
- Ubuntu 20.04 LTS  <br>
- Ubuntuの入ったコンピュータ　 <br>
- LED   <br>
- 300Ω　抵抗器 <br>
- ブレッドボード <br>
- ジャンバーコード  <br>

# 実行方法

```
$ git clone https://github.com/sakamoto-takaya/Robot_Systems_Device_Driver.git       //リポジトリのクローン 
$ cd Robot_Systems_Device_Driver                                                     //リポジトリの移動 
$ make //makeする 
$ sudo insmod myled.ko  
$ sudo chmod 666 /dev/myled0 

$ echo 文字 > /dev/myled0                                                             //文字を打ち込むとモールスを3回光らせる 
$ echo 文字 > /dev/myled0
$ echo 文字 > /dev/myled0


$ sudo rm /dev/myled0                                                                //後処理   
$ sudo rmmod myled  
```

# プログラムの解説
cher型で受け取った文字を、文字コードで判別し英数字の時に以下の処理を行った <br> 
大文字小文字問わず、if文内の文字列に該当する場合、モースル信号のトン、ツーを光らせる。 <br> 

# 動画 
Hello. My name is Takaya Sakamoto. I'm 22. Thank you.
と入力したものです <br>
[動画](https://youtu.be/2eOcMRvzSrY)

動画のように、英数字が入力されると対応するモールス信号を光らせます

# ライセンス
本リポジトリにはGPLv3が付与されています <br>
[ライセンス](https://github.com/sakamoto-takaya/Robot_Systems_Device_Driver/blob/main/LICENSE)

# 参考にしたサイト
https://ryuichiueda.github.io/robosys2020/lesson7_device_driver.html#/
