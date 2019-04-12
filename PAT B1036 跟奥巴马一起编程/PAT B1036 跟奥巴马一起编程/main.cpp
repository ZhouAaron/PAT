//
//  main.cpp
//  PAT B1036 跟奥巴马一起编程
//
//  Created by 周杰 on 2019/4/12.
//  Copyright © 2019 周杰. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    char c;
    scanf("%d %c",&n,&c);
    for (int i = 0; i<n
         ;i++) {
        if (i == 0) {
            for (int j = 0; j<n; j++) {
                printf("%c",c);
            }
            printf("\n");
        }
        while (i>0&&i<(n/2)) {
            
            printf("%c",c);
            for (int j = 0; j<n-2; j++) {
                printf(" ");
            }
            printf("%c\n",c);
            i++;
        }
        if (i==n-1) {
            for (int j = 0; j<n; j++) {
                printf("%c",c);
                
            }
            printf("\n");
        }
    }
    return 0;
}
