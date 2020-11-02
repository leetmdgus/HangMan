#include <iostream>
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
    void start();
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


void HangMan::start(){
    int choice_theme;
    std::string animal_list[] = {"dog", "cat" };
    std::string current_word;

    std::cout<<"Choice Theme: 1. animal 2. etc."<<std::endl;
    std::cout<<"choice: ";
    std::cin>>choice_theme;

    switch (choice_theme){
    case 1:
        current_word = animal_list[0];// 랜덤
    }
    
    std::cout<<current_word;

}

int main(){
    HangMan hm();
    hm.start();
    
    return 0;
}