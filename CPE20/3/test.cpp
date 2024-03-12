#include <iostream>
#include <vector>

void question_5() {
    int i {2};
    float f {1.};

    // Won't compile because you can't bitshift a float
    // std::cout << static_cast<float>(i) >> 1);
    // std::cout << float{6} >> 2;
}

void question_6() {
    short s{1};
    int i{2};
    float f{.4};

    std::cout << i/static_cast<float>(s) + i/2 + i/f;
}

void question_8() {
    std::vector<float*> ft {new float[1], new float[1], new float[1]};
    
    for (int i=0; i<3; i++) {
        float *p {ft[i]};
        *p = i;
    }

    std::cout << ft[1];
    for (int i=0; i<3; i++) {}
}

void question_7() {
    char a{'c'};
    char b{'a'};
    std::cout << b - a << "\n";
}

void question_12() {
    std::string s{"2"};
    int i{2};

    // Will cause an error due to incompatible operands
    // std::cout << s == i;
}

void question_19() {
    int first_legal {-111222333};

    // Apparently the below is a legal means of separating 1,000s
    int second_legal {111'222'333};
}

int main() {
    question_7();
    return 0;
}