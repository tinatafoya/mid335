//CMPS 335
//mid335.cpp
//
//
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

typedef enum {
    C = 1,
    Cs,
    D,
    Ds,
    E,
    F,
    Fs,
    G,
    Gs,
    A,
    As,
    B,
    END = B,
    HALF_STEPS_PER_OCTAVE = B 
} note_t;

double freq(note_t note, int octave_delta);
double unitt();


int main(int argc, char *argv[])
{
    note_t note;
    int octave_delta;

    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA>" << endl;
        return 0;
    }
    //
    note = (note_t)(toupper(argv[1][0]) - 64);
    switch(toupper(argv[1][0])) {
        case 'A': note = A; break;
        case 'B': note = B; break;
        case 'C': note = C; break;
        case 'D': note = D; break;
        case 'E': note = E; break;
        case 'F': note = F; break;
    }
    //You may call your unit test here...

    cout << "note  octave  value     diff" << endl;
    cout << "----  ------  --------  -----------" << endl;
    unitt();



    if (note > END) {
        cout << "Invalid note!" << endl;
        return 1;
    }
    octave_delta = atoi(argv[2]);
    cout << HALF_STEPS_PER_OCTAVE << endl;
    cout << freq(note, octave_delta) << endl;
    return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
    double freq;
    double factor;
    double a;
    int n;
    int octave = octave_delta - F0_octave;

    a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
    n = note - F0_note;
    freq = F0 * pow(a, (double)n);
    factor = pow(2.0, (double)octave);
    freq = freq * factor;
    return freq;
}



double unitt()
{
    double diff;
    diff =(freq(C,0)) - 16.35;
    cout << "1" << "       " << "0     " << freq(C,0) << "   " << diff  << endl;
    //16.35
    diff =(freq(Cs,0)) - 17.32;
    cout << "2" << "       " << "0     " << freq(Cs,0) << "   " << diff  << endl;
    //17.32
    diff =(freq(D,0)) - 17.32;
    cout << "3" << "       " << "0     " << freq(D,0)  << "   " << diff  << endl;
    //18.35
    diff =(freq(Ds,0)) - 19.45;
    cout << "4" << "       " << "0     " << freq(Ds,0)  << "   " << diff  << endl;
    //19.45
    diff =(freq(E,0)) - 20.6;
    cout << "5" << "       " << "0     " << freq(E,0)  << "   " << diff  << endl;
    //20.6
    diff =(freq(F,0)) - 21.83;
    cout << "6" << "       " << "0     " << freq(F,0)  << "   " << diff  << endl;
    //21.83
    diff =(freq(Fs,0)) - 23.12;
    cout << "7" << "       " << "0     " << freq(Fs,0)  << "   " << diff  << endl;
    //23.12
    diff =(freq(G,0)) - 24.5;
    cout << "8" << "       " << "0     " << freq(G,0)  << "   " << diff  << endl;
    //24.5
    diff =(freq(Gs,0)) - 25.96;
    cout << "9" << "       " << "0     " << freq(Gs,0)  << "   " << diff  << endl;
    //25.96
    diff =(freq(A,0)) - 27.5;
    cout << "10" << "      " << "0     " << freq(A,0)  << "   " << diff  << endl;
    //27.5
    diff =(freq(As,0)) - 29.14;
    cout << "11" << "      " << "0     " << freq(As,0)  << "   " << diff  << endl;
    //29.14
    diff =(freq(B,0)) - 30.87;
    cout << "12" << "      " << "0     " << freq(B,0)  << "   " << diff  << endl;
    //30.87


    diff =(freq(C,1)) - 32.7;
    cout << "1" << "       " << "1     " << freq(C,1) << "   " << diff  << endl;
    //32.7
    diff =(freq(Cs,1)) - 34.65;
    cout << "2" << "       " << "1     " << freq(Cs,1) << "   " << diff  << endl;
    //34.65
    diff =(freq(D,1)) - 36.71;
    cout << "3" << "       " << "1     " << freq(D,1)  << "   " << diff  << endl;
    //36.71    
    diff =(freq(Ds,1)) - 38.89;
    cout << "4" << "       " << "1     " << freq(Ds,1)  << "   " << diff  << endl;
    //38.89
    diff =(freq(E,1)) - 41.2;
    cout << "5" << "       " << "1     " << freq(E,1)  << "   " << diff  << endl;
    //41.2
    diff =(freq(F,1)) - 43.65;
    cout << "6" << "       " << "1     " << freq(F,1)  << "   " << diff  << endl;
    //43.65
    diff =(freq(Fs,1)) - 46.25;
    cout << "7" << "       " << "1     " << freq(Fs,1)  << "   " << diff  << endl;
    //46.25
    diff =(freq(G,1)) - 49;
    cout << "8" << "       " << "1     " << freq(G,1)  << "   " << diff  << endl;
    //49
    diff =(freq(Gs,1)) - 51.91;
    cout << "9" << "       " << "1     " << freq(Gs,1)  << "   " << diff  << endl;
    //51.91
    diff =(freq(A,1)) - 55;
    cout << "10" << "      " << "1     " << freq(A,1)  << "   " << diff  << endl;
    //55
    diff =(freq(As,1)) - 58.27;
    cout << "11" << "      " << "1     " << freq(As,1)  << "   " << diff  << endl;
    //58.27
    diff =(freq(B,1)) - 61.74;
    cout << "12" << "      " << "1     " << freq(B,1)  << "   " << diff  << endl;
    //61.74

    //2
    diff =(freq(C,2)) - 65.41;
    cout << "1" << "       " << "2     " << freq(C,2) << "   " << diff  << endl;
    //65.41
    diff =(freq(Cs,2)) - 69.3;
    cout << "2" << "       " << "2     " << freq(Cs,2) << "   " << diff  << endl;
    //69.3
    diff =(freq(D,2)) - 73.42;
    cout << "3" << "       " << "2     " << freq(D,2)  << "   " << diff  << endl;
    //73.42
    diff =(freq(Ds,2)) - 77.78;
    cout << "4" << "       " << "2     " << freq(Ds,2)  << "   " << diff  << endl;
    //77.78
    diff =(freq(E,2)) - 82.41;
    cout << "5" << "       " << "2     " << freq(E,2)  << "   " << diff  << endl;
    //82.41
    diff =(freq(F,2)) - 87.31;
    cout << "6" << "       " << "2     " << freq(F,2)  << "   " << diff  << endl;
    //87.31
    diff =(freq(Fs,2)) - 92.5;
    cout << "7" << "       " << "2     " << freq(Fs,2)  << "   " << diff  << endl;
    //92.5
    diff =(freq(G,2)) - 98;
    cout << "8" << "       " << "2     " << freq(G,2)  << "   " << diff  << endl;
    //98
    diff =(freq(Gs,2)) - 103.83;
    cout << "9" << "       " << "2     " << freq(Gs,2)  << "   " << diff  << endl;
    //103.83
    diff =(freq(A,2)) - 110;
    cout << "10" << "      " << "2     " << freq(A,2)  << "   " << diff  << endl;
    //110
    diff =(freq(As,2)) - 116.54;
    cout << "11" << "      " << "2     " << freq(As,2)  << "   " << diff  << endl;
    //116.54
    diff =(freq(B,2)) - 123.47;
    cout << "12" << "      " << "2     " << freq(B,2)  << "   " << diff  << endl;
    //123.47

    //3
    diff =(freq(C,3)) - 130.81;
    cout << "1" << "       " << "3     " << freq(C,3) << "   " << diff  << endl;
    //130.81
    diff =(freq(Cs,3)) - 138.59;
    cout << "2" << "       " << "3     " << freq(Cs,3) << "   " << diff  << endl;
    //138.59
    diff =(freq(D,3)) - 146.83;
    cout << "3" << "       " << "3     " << freq(D,3)  << "   " << diff  << endl;
    //146.83
    diff =(freq(Ds,3)) - 155.56;
    cout << "4" << "       " << "3     " << freq(Ds,3)  << "   " << diff  << endl;
    //155.56
    diff =(freq(E,3)) - 164.81;
    cout << "5" << "       " << "3     " << freq(E,3)  << "   " << diff  << endl;
    //164.81
    diff =(freq(F,3)) - 174.61;
    cout << "6" << "       " << "3     " << freq(F,3)  << "   " << diff  << endl;
    //174.61
    diff =(freq(Fs,3)) - 185;
    cout << "7" << "       " << "3     " << freq(Fs,3)  << "   " << diff  << endl;
    //185
    diff =(freq(G,3)) - 196;
    cout << "8" << "       " << "3     " << freq(G,3)  << "   " << diff  << endl;
    //196
    diff =(freq(Gs,3)) - 207.65;
    cout << "9" << "       " << "3     " << freq(Gs,3)  << "   " << diff  << endl;
    //207.65
    diff =(freq(A,3)) - 220;
    cout << "10" << "      " << "3     " << freq(A,3)  << "   " << diff  << endl;
    //220
    diff =(freq(As,3)) - 233.08;
    cout << "11" << "      " << "3     " << freq(As,3)  << "   " << diff  << endl;
    //233.08
    diff =(freq(B,3)) - 246.94;
    cout << "12" << "      " << "3     " << freq(B,3)  << "   " << diff  << endl;
    //246.94

    //4
    diff =(freq(C,4)) - 261.63;
    cout << "1" << "       " << "4     " << freq(C,4) << "   " << diff  << endl;
    //261.63
    diff =(freq(Cs,4)) - 277.18;
    cout << "2" << "       " << "4     " << freq(Cs,4) << "   " << diff  << endl;
    //277.18
    diff =(freq(D,4)) - 293.66;
    cout << "3" << "       " << "4     " << freq(D,4)  << "   " << diff  << endl;
    //293.66
    diff =(freq(Ds,4)) - 311.13;
    cout << "4" << "       " << "4     " << freq(Ds,4)  << "   " << diff  << endl;
    //311.13
    diff =(freq(E,4)) - 329.63;
    cout << "5" << "       " << "4     " << freq(E,4)  << "   " << diff  << endl;
    //329.63
    diff =(freq(F,4)) - 349.23;
    cout << "6" << "       " << "4     " << freq(F,4)  << "   " << diff  << endl;
    //349.23
    diff =(freq(Fs,4)) - 369.99;
    cout << "7" << "       " << "4     " << freq(Fs,4)  << "   " << diff  << endl;
    //369.99
    diff =(freq(G,4)) - 392;
    cout << "8" << "       " << "4     " << freq(G,4)  << "   " << diff  << endl;
    //392
    diff =(freq(Gs,4)) - 415.3;
    cout << "9" << "       " << "4     " << freq(Gs,4)  << "   " << diff  << endl;
    //415.3
    diff =(freq(A,4)) - 440;
    cout << "10" << "      " << "4     " << freq(A,4)  << "   " << diff  << endl;
    //440
    diff =(freq(As,4)) - 466.16;
    cout << "11" << "      " << "4     " << freq(As,4)  << "   " << diff  << endl;
    //466.16
    diff =(freq(B,4)) - 493.88;
    cout << "12" << "      " << "4     " << freq(B,4)  << "   " << diff  << endl;
    //493.88

    //5
    diff =(freq(C,5)) - 523.25;
    cout << "1" << "       " << "5     " << freq(C,5) << "   " << diff  << endl;
    //523.25
    diff =(freq(Cs,5)) - 554.37;
    cout << "2" << "       " << "5     " << freq(Cs,5) << "   " << diff  << endl;
    //554.37
    diff =(freq(D,5)) - 587.33;
    cout << "3" << "       " << "5     " << freq(D,5)  << "   " << diff  << endl;
    //587.33
    diff =(freq(Ds,5)) - 622.25;
    cout << "4" << "       " << "5     " << freq(Ds,5)  << "   " << diff  << endl;
    //622.25
    diff =(freq(E,5)) - 659.25;
    cout << "5" << "       " << "5     " << freq(E,5)  << "   " << diff  << endl;
    //659.25
    diff =(freq(F,5)) - 698.46;
    cout << "6" << "       " << "5     " << freq(F,5)  << "   " << diff  << endl;
    //698.46
    diff =(freq(Fs,5)) - 739.99;
    cout << "7" << "       " << "5     " << freq(Fs,5)  << "   " << diff  << endl;
    //739.99
    diff =(freq(G,5)) - 783.99;
    cout << "8" << "       " << "5     " << freq(G,5)  << "   " << diff  << endl;
    //783.99
    diff =(freq(Gs,5)) - 830.61;
    cout << "9" << "       " << "5     " << freq(Gs,5)  << "   " << diff  << endl;
    //830.61
    diff =(freq(A,5)) - 880;
    cout << "10" << "      " << "5     " << freq(A,5)  << "   " << diff  << endl;
    //880
    diff =(freq(As,5)) - 932.33;
    cout << "11" << "      " << "5     " << freq(As,5)  << "   " << diff  << endl;
    //932.33
    diff =(freq(B,5)) - 987.77;
    cout << "12" << "      " << "5     " << freq(B,5)  << "   " << diff  << endl;
    //987.77

    //6
    diff =(freq(C,6)) - 1046.5;
    cout << "1" << "       " << "6     " << freq(C,6) << "   " << diff  << endl;
    diff =(freq(Cs,6)) - 1108.73;
    cout << "2" << "       " << "6     " << freq(Cs,6) << "   " << diff  << endl;
    diff =(freq(D,6)) - 1174.66;
    cout << "3" << "       " << "6     " << freq(D,6)  << "   " << diff  << endl;
    diff =(freq(Ds,6)) - 1244.51;
    cout << "4" << "       " << "6     " << freq(Ds,6)  << "   " << diff  << endl;
    diff =(freq(E,6)) - 1318.51;
    cout << "5" << "       " << "6     " << freq(E,6)  << "   " << diff  << endl;
    diff =(freq(F,6)) - 1396.91;
    cout << "6" << "       " << "6     " << freq(F,6)  << "   " << diff  << endl;
    diff =(freq(Fs,6)) - 1479.98;
    cout << "7" << "       " << "6     " << freq(Fs,6)  << "   " << diff  << endl;
    diff =(freq(G,6)) - 1567.98;
    cout << "8" << "       " << "6     " << freq(G,6)  << "   " << diff  << endl;
    diff =(freq(Gs,6)) - 1661.22;
    cout << "9" << "       " << "6     " << freq(Gs,6)  << "   " << diff  << endl;
    diff =(freq(A,6)) - 1760;
    cout << "10" << "      " << "6     " << freq(A,6)  << "   " << diff  << endl;
    diff =(freq(As,6)) - 1864.66;
    cout << "11" << "      " << "6     " << freq(As,6)  << "   " << diff  << endl;
    diff =(freq(B,6)) - 1975.53;
    cout << "12" << "      " << "6     " << freq(B,6)  << "   " << diff  << endl;

    //7
    diff =(freq(C,7)) - 2093;
    cout << "1" << "       " << "7     " << freq(C,7) << "   " << diff  << endl;
    diff =(freq(Cs,7)) - 2217.46;
    cout << "2" << "       " << "7     " << freq(Cs,7) << "   " << diff  << endl;
    diff =(freq(D,7)) - 2349.32;
    cout << "3" << "       " << "7     " << freq(D,7)  << "   " << diff  << endl;
    diff =(freq(Ds,7)) - 2489.02;
    cout << "4" << "       " << "7     " << freq(Ds,7)  << "   " << diff  << endl;
    diff =(freq(E,7)) - 2637.02;
    cout << "5" << "       " << "7     " << freq(E,7)  << "   " << diff  << endl;
    diff =(freq(F,7)) - 2793.83;
    cout << "6" << "       " << "7     " << freq(F,7)  << "   " << diff  << endl;
    diff =(freq(Fs,7)) - 2959.96;
    cout << "7" << "       " << "7     " << freq(Fs,7)  << "   " << diff  << endl;
    diff =(freq(G,7)) - 3135.96;
    cout << "8" << "       " << "7     " << freq(G,7)  << "   " << diff  << endl;
    diff =(freq(Gs,7)) - 3322.44;
    cout << "9" << "       " << "7     " << freq(Gs,7)  << "   " << diff  << endl;
    diff =(freq(A,7)) - 3520;
    cout << "10" << "      " << "7     " << freq(A,7)  << "   " << diff  << endl;
    diff =(freq(As,7)) - 3729.31;
    cout << "11" << "      " << "7     " << freq(As,7)  << "   " << diff  << endl;
    diff =(freq(B,7)) - 3951.07;
    cout << "12" << "      " << "7     " << freq(B,7)  << "   " << diff  << endl;

    //8
    diff =(freq(C,8)) - 4186.01;
    cout << "1" << "       " << "8     " << freq(C,8) << "   " << diff  << endl;
    diff =(freq(Cs,8)) - 4434.92;
    cout << "2" << "       " << "8     " << freq(Cs,8) << "   " << diff  << endl;
    diff =(freq(D,8)) - 4698.63;
    cout << "3" << "       " << "8     " << freq(D,8)  << "   " << diff  << endl;
    diff =(freq(Ds,8)) - 4978.03;
    cout << "4" << "       " << "8     " << freq(Ds,8)  << "   " << diff  << endl;
    diff =(freq(E,8)) - 5274.04;
    cout << "5" << "       " << "8     " << freq(E,8)  << "   " << diff  << endl;
    diff =(freq(F,8)) - 5587.65;
    cout << "6" << "       " << "8     " << freq(F,8)  << "   " << diff  << endl;
    diff =(freq(Fs,8)) - 5919.91;
    cout << "7" << "       " << "8     " << freq(Fs,8)  << "   " << diff  << endl;
    diff =(freq(G,8)) - 6271.93;
    cout << "8" << "       " << "8     " << freq(G,8)  << "   " << diff  << endl;
    diff =(freq(Gs,8)) - 6644.88;
    cout << "9" << "       " << "8     " << freq(Gs,8)  << "   " << diff  << endl;
    diff =(freq(A,8)) - 7040;
    cout << "10" << "      " << "8     " << freq(A,8)  << "   " << diff  << endl;
    diff =(freq(As,8)) - 7458.62;
    cout << "11" << "      " << "8     " << freq(As,8)  << "   " << diff  << endl;
    diff =(freq(B,8)) - 7902.13;
    cout << "12" << "      " << "8     " << freq(B,8)  << "   " << diff  << endl;

    //
}

