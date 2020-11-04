# HangMan

수정일: 2020-11-03

+ 수정사항
  + 입력단어 3,4,5,6에 따른 _ 밀림 현상 해결 수정완료
  + 단어 추가

+ 수정해야할 것

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

  (출처:https://www.quora.com/Can-I-make-a-GUI-using-Visual-Studio-code)

+ 

#### 소스코드

