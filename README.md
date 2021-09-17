# 1082_INTRODUCTION_TO_COMPUTER_AND_PROGRAMMING_LANGUAGE_2
## HW1
這題讓我們想一想為什麼在程式裡0.1 + 0.2 != 0.3。  
Ans : 原因是在電腦的世界裡實際上是用二進制的方法來計算數字的，只是我們使用十進制的數字來呈現。事實上我們看到的0.1用二進制表示為2^-4 * 1.10011(0011)；0.2 = 2^-3 * 1.10011(0011)，兩者相加以後最後的位數無法捨去，變成0.30000000000000004。  
範例程式碼就讓我們了解到這點。改幾第6-8行程式碼就可以讓程式順利運行～  
範例程式碼：  
<img width="428" alt="image" src="https://user-images.githubusercontent.com/70461575/133745899-d16831af-0cdd-475c-b684-c8bdb631e187.png">   
更改版本：  
<img width="389" alt="image" src="https://user-images.githubusercontent.com/70461575/133745148-6e25ffb1-8307-4d3c-88f5-97874becb6ec.png">
  
  未完待續...
  
