# HangMan

수정일: 2020-11-05

+ 수정사항
  + 입력단어 3,4,5,6에 따른 _ 밀림 현상 해결 수정완료
  + 동물 단어 추가
+ 나라 주제 + 단어 추가
  
+ 수정해야할 것

  + 타원그리기 예제에서 컴파일 에러 발생

+ 추가해야할 것

  + 그래픽 추가 
  + 주제 추가 + 단어 추가
  + 랜덤으로 단어 선택하는 것 만들기 

  

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



#### 소스코드



