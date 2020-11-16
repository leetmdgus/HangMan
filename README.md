# HangMan

수정일: 2020-11-12

+ 수정사항
  + 입력단어 3,4,5,6에 따른 _ 밀림 현상 해결 수정완료
  + 동물 단어 추가
  + 나라 단어 삭제 (ex. Kingdom of Denmark)
+ 나라 주제 + 단어 추가
  
+ 수정해야할 것

  + 타원그리기 예제에서 컴파일 에러 발생

+ 추가해야할 것

  + 그래픽 추가 
  + 주제 추가 + 단어 추가
  + 랜덤으로 단어 선택하는 것 만들기 
  + 게임을 설명하는 것 만들기

  

+ 행맨게임

  + **행맨**(Hangman)는 상대방이 생각하는 단어를 맞춰가는 게임이다.

+ 행맨을 하기 앞서 Gui를 공부한다.

+ 생성자및 스트링 클래스를 사용하여 행맨을 구현한다.

+ 구현한 행맨을 GUI형식으로 변환해본다.



#### GUI STUDY

+ 평소 visual studio code로 프로그램을 구현하지만 visual studio code로 GUI를 구현하는 것에 대한 정보보다 visual studio 를 사용하여 구현한 자료가 많아 visual studio 를 설치하려 하려 했다. 하지만 visual studio code로도 충분히 구현할 수 있을 거란 생각이 들어 HangMan게임을 visual studio code로 만들 예정이다. 

+ 아래 예제는 visual studio code로 만든 윈도우 창 예제이다. 

  ```c++
  #include <windows.h> 
  int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
   LPSTR lpCmdLine, int nCmdShow) 
  { 
   MessageBox(NULL, "Goodbye, cruel world!", "Note", MB_OK); 
   return 0; 
  } 
  ```

  (참고:https://www.quora.com/Can-I-make-a-GUI-using-Visual-Studio-code)

+ 아래 예제는 타원그리기 예제이다

  ```c++
  #include <conio.h>
  #include <windows.h>
  
  int main(){
      // Z-Order 상에서 가장 앞쪽에 출력된 Window핸들을 얻는다.
      // 콘솔 프로그램이 실행될 때 콘솔 창 (Window)이 먼저 생성되어
      // 화면에 출력되기 때문에 콘솔창의 핸들 값이 h_wnd 변수에 저장됨.
  
      HWND h_wnd = GetForegroundWindow();
      //h_wd에 그림을 그릴 수 있는 DC핸들을 얻는다.
      HDC h_dc = GetDC(h_wnd);
  
      //콘솔창에서 얻은 DC핸들 값을 사용해서 타원을 그린다.
      //(50,50)에서 (100,100)을 연결한 사각형에 내접하는 타원을 그림!!
      Ellipse(h_dc, 50,50,100,100);
  
      //콘솔 창에서 얻은 DC핸들을 반환한다.
      ReleaseDC(h_wnd,h_dc);
      //종료와 관련된 텍스트가 출력되어 화면에 지워지는 현상을 막기위해
      //키를 하나 누를 때까지 대기
      getch();
      return 0;
  
  }
  ```

  + (참고 : https://blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221618487792&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView)
  + 현재 이 코드를 작성하고 돌렸을 때 에러가 난다. 그 이유를 찾을 필요가 있다.

+  http://soen.kr/lecture/win32api/win32lec.htm



#### Handle 이란?

+ 운영체제에 의해 관리되는 장치나 해당 장치를 사용하기 위해 필요한 정보들을 리소스(Resource)라고 부른다. 운영체제의 리소스는 대부분 메모리로 구성되어 있기 때문에 포인터를 사용하여 주소에 접근할 수 있다. 하지만 리소스의 주소를 응용프로그램이 직접사용하게 되면 운영체제가 자신의 내부에 있는 정보를 안전하게 관리할 수 없다.

+ 따라서 운영체제는 자신의 리소스를 안전하게 관리하기 위해 주소를 사용하는 포인터 대신에 '핸들'을 사용한다.

+ Handle

  + 운영체제 내부에 잇는 어떤 리소스의 주소를 정수로 치환한 값

+ ex

  + 리소스의 주소가 0xE671927이라면 응용프로그램에는 이 주소를 알려주지 않고 이 주소와 연결된 핸들값 100을 전달한다.

+ Win32프로그램에서 핸들 값을 저장할 때는 HANDLE이라는 자료형을 기본적으로 사용하고, 이 값은 32비트 운영체제의 경우 unsigned int 자료형과 동일하다. 

+ API함수를 사용할 때 자신이 가지고 있는 핸들값을 다른 리소스에 사용하는 실수를 막기 위해 리소스별로 다른 자료형을 사용한다. 

+ ex 

  + 핸들을 의미하는 자료형은 모두 앞에 H로 시작한다.
  + 해당 자원을 의미하는 영문명칭을 사용한다.
  + 따라서 마우스 커서의 핸들 값은 HCURSOR라는 자료형을 사용하며 아이콘의 핸들값은 HICON을 사용한다.

  ```
  HCURSOR h_my_cursor = LoadCursor(NULL, IDC_ARROW);
  HICON h_my_icon = LoadIcon(NULL, IDI_APPLICSATION);
  ```

+ 참고: https://blog.naver.com/tpsware/221464968465



#### 소스코드

``` c++
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

class HangMan{
private:
    bool is_scaffold;
    bool is_head;
    bool is_body;
    bool is_left_hand;
    bool is_right_hand;
    bool is_left_leg;
    bool is_right_leg;

public:
    HangMan(){
        is_scaffold = false; 
        is_head = false; 
        is_body = false;
        is_left_hand = false;
        is_right_hand = false;
        is_left_leg = false;
        is_right_leg = false;
    }
    
    void create_scaffold();
    void create_head();
    void create_body();
    void create_left_hand();
    void create_right_hand();
    void create_left_leg();
    void create_right_leg();
    int start();
};

void HangMan::create_scaffold(){
    is_scaffold = true;
    std::cout<<"Create Scaffold"<<std::endl;
}
void HangMan::create_head(){
    is_head = true;
    std::cout<<"Create Head"<<std::endl;
}
void HangMan::create_body(){
    is_body = true;
    std::cout<<"Create Body"<<std::endl;

}
void HangMan::create_left_hand(){
    is_left_hand = true;
    std::cout<<"Create Left Hand"<<std::endl;
}
void HangMan::create_right_hand(){
    is_right_hand = true;
    std::cout<<"Create Right Hand"<<std::endl;
}
void HangMan::create_left_leg(){
    is_left_leg = true;
    std::cout<<"Create Left Leg"<<std::endl;
}
void HangMan::create_right_leg(){
    is_right_leg = true;
    std::cout<<"Create Right Leg"<<std::endl;
}


int HangMan::start(){
    int choice_theme;
    std::string animal_list[] = {"fox",",dog", "cat","leopard","hyena","parrot","owl"
                                    ,"lion","eagle","hen","cow","ox","chicken","crane","bird"
                                    ,"tiger","swan","goose","giraffe"};
    std::string country_list[] = {"Guam", "Nigeria","Nepal","NewZealand"
                                    , "Korea","Germany","Laos"
                                    , "Russia", "Mexico","Mongolia","Vietnam"
                                    , "Brazil", "Belgium", "SaudiArabia", "SriLanka"
                                    , "Sweden", "Swiss","Spain","Argentina"
                                    , "Iceland"};
    std::string current_word;

    std::cout<<"Choice Theme: 1. Animal 2. Country 3. etc."<<std::endl;
    std::cout<<"choice: ";
    std::cin>>choice_theme;
	
    srand((unsigned int)time(NULL));
	int num = rand()%5;
	
	switch (choice_theme){
	case 1:
        current_word = animal_list[num];
        break;// ?�덤
    case 2:
        current_word = country_list[num];
        break;
    }
	
    int current_length = current_word.size();
    int z = 0;

    for(int j = 0; j <current_length;j++){
        z++;
    }

    std::string view;

    for(int i = 0; i < current_length; i++){
       view.insert(i," _ "); 
    }

    char alphabet;
    int changePoint = 0;
    int create = 0;
        
    while(1){
        std::cout<<view<<std::endl;
        
        Sleep(700);
        //alphbet input
        // char alphabet;
        std::cout<<"Put your gues with Capital letter: ";
        std::cin>>alphabet;


        //std::cout<<current_word<<std::endl;
        //.at -> certain region char access.
        // int changePoint = 0;
        for(int i = 0; i < current_length ;i++){
        char compare = current_word.at(i); 
            if(compare == alphabet){
                    changePoint ++;
                    std::string stralpha;
                    stralpha = alphabet;
                    view.erase(2*i+z,1);
                    view.insert(2*i+z,stralpha);
            }
        }
        // int create = 0;
        if(changePoint == 0){
            create ++;
            switch (create){
            case 1:
                create_scaffold();
                break;
            case 2:
                create_head();
                break;
            case 3:
                create_body();
                break;
            case 4:
                create_left_hand();
                break;
            case 5:
                create_right_hand();
                break;
            case 6:
                create_left_leg();
                break;
            case 7:
                create_right_leg();
                Sleep(2000);
                std::cout<<"your word: "<<current_word<<std::endl;
                std::cout<<"game end"<<std::endl;
                Sleep(2000);
                return 0;
            } 
        }
        changePoint = 0;
        int trans = 0;
        for(int i = 0; i < current_length ;i++){
            char compare = view.at(2*i+z); 
            if(compare == '_'){
                    trans++;
                    break;

            }
        }
        if(trans ==  0){
            std::cout<<view<<std::endl;
            Sleep(2000);
            std::cout<<"you win"<<std::endl;
            return 0;
        }

    }   
}

int main(){
    HangMan hm = HangMan();
    hm.start();
    Sleep(3000);
    //.insert -> string insert in located region
    //.size, . length -> size of string
    //.at -> certain region char access.
    //.c_str -> string change to char*



    return 0;
}

```



최종 수정일: 2020-11-16

