//window 창 키 나오게 하기
#include <conio.h>
#include <windows.h>
// 참고 : https://blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221618487792&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
// 참고 : http://soen.kr/lecture/win32api/win32lec.htm

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
