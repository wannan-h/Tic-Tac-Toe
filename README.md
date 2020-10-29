# Tic-Tac-Toe  
A simple Tic Tac Toe game(using c++)  
  
是根据知乎文章的思路编写的基础井字棋游戏  

用C语言实现井字棋（上） - Milo Yip的文章 - 知乎  
https://zhuanlan.zhihu.com/p/39581573  
  
Tips：    
  写代码的时候犯了一个很蠢的错误：{    
    int a=0;   
    int b=0;  
    int c=2;  
      (a==b==c)   
    = (a==b)==c   
    = (1)==c   
    = false  
  }  
这是在判断玩家O/X下完一步后，是否获得游戏胜利时，没有注意到的地方。  
