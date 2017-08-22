uint8_t charSet[39][5] = {
    {2, 5, 7, 5, 5},//A
    {6, 5, 7, 5, 7},//B
    {7, 4, 4, 4, 7},//C
    {6, 5, 5, 5, 6},//D
    {7, 4, 7, 4, 7},//E
    {7, 4, 6, 4, 4},//F
    {15, 8, 11, 9, 15},//G
    {5, 5, 7, 5, 5},//H
    {7, 2, 2, 2, 7},//I
    {7, 2, 2, 2, 6},//J
    {5, 5, 6, 5, 5},//K
    {4, 4, 4, 4, 7},//L
    {17, 27, 21, 17, 17},//M
    {17, 25, 21, 19, 17},//N
    {7, 5, 5, 5, 7},//O
    {7, 5, 7, 4, 4},//P
    {30, 18, 18, 22, 31},//Q
    {7, 5, 7, 6, 5},//R
    {7, 4, 7, 1, 7},//S
    {7, 2, 2, 2, 2},//T
    {5, 5, 5, 5, 7},//U
    {5, 5, 5, 5, 2},//V
    {17, 17, 21, 27, 17},//W
    {5, 2, 2, 2, 5},//X
    {5, 5, 2, 2, 2},//Y
    {7, 1, 2, 4, 7},//Z
    {7, 5, 5, 5, 7},//O
    {2, 6, 2, 2, 7},//1
    {7, 1, 7, 4, 7},//2
    {7, 1, 3, 1, 7},//3
    {8, 10, 15, 2, 2},//4
    {7, 4, 7, 1, 7},//5
    {7, 4, 7, 5, 7},//6
    {14, 2, 7, 2, 2},//7
    {7, 5, 7, 5, 7},//8
    {7, 5, 7, 1, 1},//9
    {0, 2, 0, 2, 0},//:
    {0, 1, 2, 4, 0},///
    {0, 0, 0, 0, 0}//[whitespace]
};



int getWidthString(String inputStr){
  int x = 0;
  int inputInts[inputStr.length()];
  for (int i = 0; i < inputStr.length(); i++){
    if(((int)inputStr[i] >= 97) && ((int)inputStr[i] <= 122)){
      inputInts[i] = ((int)tolower(inputStr[i]))-97;
    }
    else if(((int)inputStr[i] >= 48) && ((int)inputStr[i] <= 57)){
      inputInts[i] = ((int)tolower(inputStr[i]))-22;     
    }
    else if((int)inputStr[i] == 58){
      inputInts[i] = 36;
    }
    else if((int)inputStr[i] == 47){
      inputInts[i] = 37;
    }
    else if((int)inputStr[i] == 32){
      inputInts[i] = 38;
    }
    else{
      inputInts[i] = 23;
    }
  
  }
    
  for(int j = 0; j < inputStr.length(); j++){
    int width = 3;
    int largest = 0;
    for(int i = 0; i < 5; i++){
      if(charSet[inputInts[j]][i] > largest){
        largest = charSet[inputInts[j]][i];  
      }
    }
    if(largest >= 8){
      if(largest < 16){
        width = 4;  
      }
      else{
        width = 5;  
      }
    }
    x += width + 1;
  }
  return x;
}

void writeString(String inputStr, int x, int y, bool color){
  int inputInts[inputStr.length()];
  for (int i = 0; i < inputStr.length(); i++){
    if(((int)tolower(inputStr[i])>= 97) && ((int)tolower(inputStr[i]) <= 122)){
      inputInts[i] = ((int)tolower(inputStr[i]))-97;
    }
    else if(((int)tolower(inputStr[i]) >= 48) && ((int)tolower(inputStr[i]) <= 57)){
      inputInts[i] = ((int)tolower(inputStr[i]))-22;     
    }
    else if((int)inputStr[i] == 58){
      inputInts[i] = 36;
    }
    else if((int)inputStr[i] == 47){
      inputInts[i] = 37;
    }
    else if((int)inputStr[i] == 32){
      inputInts[i] = 38;
    }
    else{
      inputInts[i] = 23;
    }
  
  }  
  
  for(int j = 0;j < inputStr.length(); j++){
    int width = 3;
    int largest = 0;
    for(int i = 0; i < 5; i++){
      if(charSet[inputInts[j]][i] > largest){
        largest = charSet[inputInts[j]][i];  
      }
    }
    if(largest >= 8){
      if(largest < 16){
        width = 4;  
      }
      else{
        width = 5;  
      }
    }
    matrix.drawBitmap(x-8+width, y, charSet[inputInts[j]], 8, 5, LED_ON);
    x += width + 1;
  }
}
