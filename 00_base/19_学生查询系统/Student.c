//
//  Student.c
//  19_学生查询系统
//
//  Created by 黄德宇 on 2025/4/12.
//

#include "Student.h"

Student *stus = NULL;
int stuLen = 0;

/**
 * 进入系统
 */
void initSystem(void) {
    initStudents();
    int quitFlag = 0;
    while (!quitFlag) {
        printMenu();
        int choice;
        printf("请输入您的选择: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            searchStudent();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            removeStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
        default:
            quitFlag = 1;
            printf("感谢使用本系统！\n");
            break;
        }
    }
}

void initStudents(void) {
    Student initStus[] = {{1, "xiaoming", GenderMale, 75},
                          {2, "xiaohong", GenderMale, 60},
                          {3, "xiaogang", GenderMale, 80},
                          {4, "xiaofang", GenderFemale, 65},
                          {5, "xiaohua", GenderMale, 70}};
    int len = sizeof(initStus) / sizeof(Student);
    stus = malloc(len * sizeof(Student));
    if (stus == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        stus[i].id = initStus[i].id;
        stus[i].gender = initStus[i].gender;
        stus[i].score = initStus[i].score;
        stus[i].name =
            (char *)malloc((strlen(initStus[i].name) + 1) * sizeof(char));
        if (stus[i].name == NULL) {
            printf("内存分配失败！\n");
            // 释放之前分配的内存
            for (int j = 0; j < i; j++) {
                free(stus[j].name);
            }
            free(stus);
            return;
        }
        strcpy(stus[i].name, initStus[i].name);
    }
    stuLen = len;
}
/**
 * 打印一级菜单
 */
void printMenu(void) {
    printf("欢迎进入学生查询系统\n");
    printf("1. 查询学生\n");
    printf("2. 添加学生\n");
    printf("3. 删除学生\n");
    printf("4. 修改学生信息\n");
    printf("5. 退出系统\n");
}

/**
 * 查询学生菜单
 */
void searchStudent(void) {
    int quitFlag = 0;
    while (!quitFlag) {
        printf("查询学生菜单\n");
        printf("1. 查询所有学生\n");
        printf("2. 通过编号查询学生\n");
        printf("3. 通过姓名查询学生\n");
        printf("4. 通过性别查询学生\n");
        printf("5. 返回上一级菜单\n");

        int choice;
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            searchAllStudent();
            break;
        case 2:
            searchStudentById();
            break;
        case 3:
            searchStudentByname();
            break;
        case 4:
            searchStudentByGender();
            break;
        case 5:
        default:
            quitFlag = 1;
            break;
        }
    }
}

/**
 * 打印学生
 */
void printStydent(Student stu) {
    char *gender = stu.gender == GenderMale ? "男" : "女";
    printf("编号：%-4d姓名：%-15s性别：%-5s成绩：%-10.0lf\n", stu.id, stu.name,
           gender, stu.score);
}

/**
 * 查询所有学生
 */
void searchAllStudent(void) {
    for (int i = 0; i < stuLen; i++) {
        printStydent(stus[i]);
    }
}

/**
 * 通过编号
 */
void searchStudentById(void) {
    printf("请输入学生id:");
    rewind(stdin);
    int id;
    scanf("%d", &id);
    for (int i = 0; i < stuLen; i++) {
        if (stus[i].id == id) {
            printStydent(stus[i]);
            return;
        }
    }
}
/**
 * 通过姓名
 */
void searchStudentByname(void) {
    printf("请输入学生姓名:");
    rewind(stdin);
    char name[20];
    if (fgets(name, sizeof(name), stdin) != NULL) {
        size_t nameLen = strlen(name);
        if (nameLen > 0 && name[nameLen - 1] == '\n') {
            name[nameLen - 1] = '\0';
        }
        for (int i = 0; i < stuLen; i++) {
            char *stuName = stus[i].name;
            // 模糊查询
            if (strstr(stuName, name) != NULL) {
                printStydent(stus[i]);
            }
        }
    }
}

/**
 * 通过性别
 */
void searchStudentByGender(void) {
    printf("请输入学生性别(0: 男, 1: 女): ");
    rewind(stdin);
    int genderInput;
    scanf("%d", &genderInput);
    Gender gender = genderInput == 0 ? GenderMale : GenderFemale;
    for (int i = 0; i < stuLen; i++) {
        if (stus[i].gender == gender) {
            printStydent(stus[i]);
        }
    }
}

/**
 * 添加学生
 */
void addStudent(void) {
    Student *stu = inputStudent();

    int lastId = stus[stuLen - 1].id;
    stu->id = lastId + 1;
    stus = realloc(stus, (stuLen + 1) * sizeof(Student));
    if (stus == NULL) {
        printf("内存分配失败！\n");
        return;
    }
    stus[stuLen].id = stu->id;
    stus[stuLen].gender = stu->gender;
    stus[stuLen].score = stu->score;
    stus[stuLen].name = (char *)malloc((strlen(stu->name) + 1) * sizeof(char));
    if (stus[stuLen].name == NULL) {
        printf("内存分配失败！\n");
        return;
    }
    strcpy(stus[stuLen].name, stu->name);
    stuLen++;

    printf("添加成功！\n");
}

/**
 * 删除学生
 */
void removeStudent(void) {
    printf("请输入学生编号:");
    int id;
    scanf("%99d", &id);
    for (int i = 0; i < stuLen; i++) {
        if (stus[i].id != id) {
            continue;
        }
        if (stus[i].name != NULL) {
            free(stus[i].name);
        }
        for (int j = i; j < stuLen - 1; j++) {
            stus[j] = stus[j + 1];
        }
        stuLen--;
        return;
    }
    printf("未找到该学生！");
}

void updateStudent(void) {
    printf("请输入学生编号：");
    int id;
    scanf("%10d", &id);
    for (int i = 0; i < stuLen; i++) {
        if (stus[i].id != id) {
            continue;
        }

        Student *stu = inputStudent();
        stus[i].gender = stu->gender;
        stus[i].score = stu->score;
        strcpy(stus[i].name, stu->name);
        printf("更行成绩成功！");
        return;
    }
    printf("未找到该学生！");
}
/**
 * 获得一个输入的学生
 */
Student *inputStudent(void) {
    Student *stu = malloc(sizeof(Student));
    char tempName[21];
    printf("请输入学生姓名:");
    scanf("%20s", tempName);
    stu->name = malloc(strlen(tempName) + 1);
    if (stu->name == NULL) {
        printf("内存分配失败！\n");
        exit(0);
    }
    strcpy(stu->name, tempName);

    printf("请输入学生性别(0: 男, 1: 女): ");
    int genderInput;
    scanf("%d", &genderInput);
    stu->gender = genderInput == 0 ? GenderMale : GenderFemale;
    printf("请输入学生成绩:");
    scanf("%f", &stu->score);
    return stu;
}
