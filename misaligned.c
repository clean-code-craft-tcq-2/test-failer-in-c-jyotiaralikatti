#include <stdio.h>
#include <assert.h>
const int N_MAJ_COLORS = 5;
const int N_MIN_COLORS = 5;

typedef struct 
{
    char* Maj_Color;
    char* Min_color;
}ColorPair_set;

ColorPair_set Get_Each_ColorPair_set(int n);
int Test_Get_Each_ColorPair_set(int);
int Test_printColorMap(void);

int printColorMap() 
{
    ColorPair_set ColorPair[N_MAJ_COLORS*N_MIN_COLORS];
    
    int i = 0,j=0;
    for(i = 0; i < N_MAJ_COLORS; i++) {
         for(j = 0; j < N_MIN_COLORS; j++) {
        ColorPair[i * 5 + j] = Get_Each_ColorPair_set(i * 5 + j);
            printf("%d | %s | %s\n", i * 5 + j, ColorPair[i * 5 + j].Maj_Color, ColorPair[i * 5 + j].Min_color);
        }
    }
    return i*j;
}

int main() {
    int result;
    result = printColorMap();//Test_printColorMap();
    assert(result==25);
    assert(result == N_MAJ_COLORS*N_MIN_COLORS);
    
    // check if each time, color pair was received by calling Get_Each_ColorPair_set;
    // Hence to make sure all required values got printed. Bcz the functionality cannot be determined just by returning i*j
    assert(result == Test_printColorMap());
    //printf("%d",Test_printColorMap());
    
   printf("All is well (maybe!)\n");
    return 0;
}

ColorPair_set Get_Each_ColorPair_set(int n)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    ColorPair_set ColorPair;

    ColorPair.Maj_Color = (char*)majorColor[n/N_MAJ_COLORS];
    ColorPair.Min_color = (char*)minorColor[n%N_MIN_COLORS];

    return ColorPair;
}

int Test_Get_Each_ColorPair_set(int count)
{
   return count++;
}

int Test_printColorMap()
{
    int count=0,r;
        int i = 0,j=0;
    for(i = 0; i < N_MAJ_COLORS; i++) {
         for(j = 0; j < N_MIN_COLORS; j++) {
        r = Test_Get_Each_ColorPair_set(count);
        }
    }
    return r;
}
