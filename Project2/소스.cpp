#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>

struct _finddata_t fd;

int isFileOrDir()
{
    if (fd.attrib & _A_SUBDIR)
        return 0; // 디렉토리면 0 반환
    else
        return 1; // 그밖의 경우는 "존재하는 파일"이기에 1 반환

}

void FileSearch(char file_path[])
{
    intptr_t handle;
    int check = 0;
    char file_path2[_MAX_PATH];

    strcat(file_path, "\\");
    strcpy(file_path2, file_path);
    strcat(file_path, "*");

    if ((handle = _findfirst(file_path, &fd)) == -1)
    {
        printf("No such file or directory\n");
        return;
    }
    int whichFile, numOfFile = 0;
    char tmpPath[_MAX_PATH], *ary[10];
    while (_findnext(handle, &fd) == 0) {
        while (_findnext(handle, &fd) == 0)
        {
            char file_pt[_MAX_PATH];
            strcpy(file_pt, file_path2);
            printf("\n이거 내꺼임 %s\n", file_path2);
            strcat(file_pt, fd.name);

            check = isFileOrDir();    //파일인지 디렉토리 인지 식별

            if (check == 0 && fd.name[0] != '.' && fd.size == 0)
            {
                printf("[%d] 파일명 : %s, 크기:%d\n", numOfFile, file_pt, fd.size);
                ary[++numOfFile] = file_pt;
                printf("%s\n", ary[numOfFile]);
                
                /* FileSearch(file_pt);  */  //하위 디렉토리 검색 재귀함수
            }
            else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
            {
                printf("파일명 : %s, 크기:%d\n", file_pt, fd.size);
            }
            
        }
        
        printf("\n ary[0]: %s \n", ary[1]);
        printf("\n ary[1] : %s \n", ary[2]);
        printf("파일 선택 해주세요 : ");
        scanf("%d", &whichFile);
        FileSearch(ary[whichFile]);
    }
    
    _findclose(handle);
}

int main()
{
    char file_path[_MAX_PATH] = "C:\\capture\\";    //C:\ 경로 탐색

    FileSearch(file_path);

    return 0;
}
