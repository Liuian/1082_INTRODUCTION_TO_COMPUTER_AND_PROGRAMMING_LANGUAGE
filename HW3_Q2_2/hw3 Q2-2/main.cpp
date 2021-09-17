# include <iostream>
# define N 5
using namespace std;
int index_arr[N] = {0,1,2,3,4};
int value_arr[N] = {0,1,2,3,4};

// Initial the label
void initial(){
    for (int i=0; i<N; i++){
        value_arr[i] = index_arr[i];
    }
}

//identify whether array u and array v are the same
int Identification(int u, int v){

    //if u == v
    
    return 1;
    // if u!=v
    return 0;
}

void Rotation(){
     for(int i=0; i<4; i++){
        value_arr[i] = index_arr[i+1];
     }
     if(int i=4){
        value_arr[i] = index_arr[0];
     }
    for (int i=0; i<N; i++){
        index_arr[i] = value_arr[i];
    }
}


void Reflection(int reflection_axis){
    int M;
    int H;
    for(int n=-2;n<=2;n++){
         M=reflection_axis+n;
         H=reflection_axis-n;
        if(M<0){
            M=M+5;
        }
        if(M>4){
            M=M-5;
        }
        if(H<0){
            H=H+5;
        }
        if(H>4){
            H=H-5;
        }
        value_arr[M]=index_arr[H];
    }
}
int main(){
    cout<<"belows are the reflection"<<endl;
    for (int axis = 0; axis<5; axis++){
        Reflection(axis);
        for(int i =0; i<5; i++){
            cout<<value_arr[i];
        }
        cout<<endl;
        Initial();
    }
    Initiall();
    cout<<"belows are the rotation"<<endl;
    for (int rotation = 0; rotation<5; rotation++){
        Rotation();
        for(int i =0; i<5; i++){
            cout<<value_arr[i];
        }
        cout<<endl;
    }
    cout<<"belows are the reflection with rotation"<<endl;
    Initial();
    for (int axis = 0; axis<5; axis++){
        // Reflection first then rotation
        Reflection(axis);
        Rotation();
        for(int i =0; i<5; i++){
            cout<<value_arr[i];
        }
        cout<<endl;
        initial();
    }
    return 0;
}
