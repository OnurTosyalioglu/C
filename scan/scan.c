int scan_int(){
    int number;
    number = 0;
    scanf("%d",&number);
    return number;
}

double scan_double(){
    double number;
    number = 0.0f;
    scanf("%lf",&number);
    return number;
}

float scan_float(){
    float number;
    number = 0.0f;
    scanf("%f",&number);
    return number;
}

char scan_char(){
    char ch;
    ch = '\0';
    scanf("%c",&ch);
    return ch;
}

char* scan_string(int size){
    char *str;
    str = (char *)malloc(size * sizeof(char));
    scanf("%s",str);
    return str;
}
