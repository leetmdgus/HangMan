#include <iostream>
#include <windows.h>

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
    std::string animal_list[] = {"dog", "cat" };
    std::string current_word;

    std::cout<<"Choice Theme: 1. animal 2. etc."<<std::endl;
    std::cout<<"choice: ";
    std::cin>>choice_theme;

    switch (choice_theme){
    case 1:
        current_word = animal_list[0];// ?úÎç§
        
    }

    int current_length = current_word.size();
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
                    view.erase(2*i+3,1);
                    view.insert(2*i+3,stralpha);
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
                std::cout<<"game end"<<std::endl;
                return 0;
            } 
        }
        changePoint = 0;
        int trans = 0;
        for(int i = 0; i < current_length ;i++){
            char compare = view.at(2*i+3); 
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
