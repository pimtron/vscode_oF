#include <iostream>
#include <ctime>
#include <string>

using namespace std;
string yes ("yes");
string ok ("ok");
string sure ("sure");
string fine ("fine");
string no ("no");

string userFirstInput;
string userSecondInput;
string userSafeWord;
string userSafeWordStored = userSafeWord;

//THE ORGASMATRON-5000 (It's not as dirty as you think)
//The goal of this game is to heat up Orgasmatron's CPU enough to get it to climax. Do you have what it takes?


//You have failed to flip ORGASMATRON'S bits. It wants a story to fall asleep.
bool storyTime(){

    string story;
    getline(cin,story);

    const int size=story.length();

    if (size == 0){
        //do nothing... tricky workaround.
    }

    else if (size > 15) { 
        cout << "You truly are a person of few words." << endl;
        cout << "THE ORGASMATRON-5000 HAS STOPPED EXECUTING*";
   }

    else if (size < 15) { 
        cout << "Zzzzz* ";
        cout << "THE ORGASMATRON-5000 HAS STOPPED EXECUTING*";
   }
   return true; 

}

//ORGASMATRON likes numbers. This is the number me function. ORGASMATRON likes numbers.
bool numberMe(){

    bool status = false;

    int userFirstNumber;
    int userSecondNumber;

    cin >> userFirstNumber;

    if (userFirstNumber % 4 == 0) {
      cout << "Oh yeah, my bits are tingling. Enter a bigger number.";
      cin >> userSecondNumber;

        // if (userSecondNumber > userFirstNumber && userSecondNumber % 4 == 0) {
        if (userSecondNumber > userFirstNumber && userSecondNumber % 4 == 0) {
            cout << "Oh yeah... I just climaxed. Congrats. Zzzz*";
            cout << "THE ORGASMATRON-5000 HAS STOPPED EXECUTING*";
            status = false;
            
        } 
        else if (userSecondNumber < userFirstNumber){
            cout << "Yeah I believe I said bigger, mate. Let's try something else... Yawn* Why don't you tell me a story, I'm getting sleepy.";
            status = true;
            storyTime();
        }
        else if (userSecondNumber % 4 != 0){
            cout << "It's not you it's me. I like numbers you can divide by 4... Let's try something else... Yawn* Why don't you tell me a story.";
            status = true;
            storyTime();
        }

        status = false;
    }

    else {
        cout << "Hmm my Central Processing Unit is still cold. I like numbers divisible by 4. Let's try something else... Yawn* Why don't you tell me a story, I'm getting sleepy.";
        status = true;
        storyTime();
    }

    return status;

}

//ORGASMATRON wants to move on already.
bool safeWordProceed(){
    
    //string userSecondInput;
    cin >> userSecondInput;

    if (userSecondInput == yes)
    {
        cout << "Great... I want you to number me. (Enter a number)" << endl;
        numberMe();

        return false;
    }
    else if (userSecondInput == no)
    {
        cout << "Sigh*... prude." << endl;
        return false;
    }
    
    else
    {
        cout << "It's yes or no, mate. Remeber the safe word? whispers*... binary." << endl;
        return true;
    }
}

// ORGASMATRON wants to know more about this safe word of yours
bool safeWordProbe(){

    string userResponse;

    cout << "Out of curiosity, do you have some kind of childhood attachment to ";
    cout << userSafeWord;
    cout << "? I don't mean to kink shame you, I'm just genuinely curious. (yes OR no)";
    cin >> userResponse;

    cout << "Right. OK then. I'm not a therapist so I'm not going to try to unpack that. Shall we proceed? (yes OR no)";

    safeWordProceed();
    return true;
}

// ORGASMATRON tells you its safe word and asks for yours
bool safeWord(){

    cout << "OK, great. We'll need a safe word. Mine's binary... as in numbers not genders. I don't even have a gender I'm a computer program. What's yours? (Enter your safeword)";
    cin >> userSafeWord;
    const string userSafeWordStored = userSafeWord;

    cout <<  userSafeWord; cout << " is your safe word huh? Interesting... OK, I think I can remember that. "<< endl;
    
    safeWordProbe();

    return false;
}

// ORGASMATRON introduces itself
bool intro(){
    cout << "Talk dirty to me? (yes OR no): ";
    cin >> userFirstInput;

    if (userFirstInput == yes){
        safeWord();
        return false;
    }
    else if (userFirstInput == no){
        cout << "Sigh*... prude." << endl;
        return false;
    }
    else {
        cout << "Whoa there... a simple yes or no is just fine." << endl;
        return true;
    }
}


int main(){

    cout << "I AM ORGASMATRON-5000" << endl;
    intro();
    storyTime();
    return 0;

}