//
//  Student.h
//  19_学生查询系统
//
//  Created by 黄德宇 on 2025/4/12.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    GenderMale, // 男
    GenderFemale
} Gender;

typedef struct {
    int id;
    char* name;
    Gender gender;
    float score;
} Student;

/**
 * 进入系统
 */
void initSystem(void);

/**
 * 初始化学生
 */
void initStudents(void);

/**
 * 打印一级菜单
 */
void printMenu(void);

/**
 * 查询学生菜单
 */
void searchStudent(void);

/**
 * 打印学生
 */
void printStydent(Student stu);

/**
 * 查询所有学生
 */
void searchAllStudent(void);

/**
 * 通过编号
 */
void searchStudentById(void);

/**
 * 通过姓名
 */
void searchStudentByname(void);

/**
 * 通过性别
 */
void searchStudentByGender(void);

/**
 * 添加学生
 */
void addStudent(void);

/**
 * 删除学生
 */
void removeStudent(void);

/**
 * 修改学生
 */
void updateStudent(void);

/**
 * 获得一个输入的学生
 */
Student* inputStudent(void);

#endif /* Student_h */
