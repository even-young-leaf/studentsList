#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//该注释用于测试git上传
struct student {
    char sname[10];
    char sno[10];
    int sage;
    int ssex;
    char sclass[10];
    struct student *next;
};

struct student *createHead() {
    struct student *head = (struct student *)malloc(sizeof(struct student));
    if(head == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    head->next = NULL;
    return head;
}

struct student *createNode(char const *sname,char const *sno,int sage,int ssex,char const *sclass) {
    struct student *p = (struct student *)malloc(sizeof(struct student));
    strncpy(p->sname,sname,strlen(sname));
    strncpy(p->sno,sno,strlen(sno));
    p->sage = sage;
    p->ssex = ssex;
    strncpy(p->sclass,sclass,strlen(sclass));
    p->next = NULL;
    return p;
}
void insert(struct student *head,struct student *p) {
    struct student *p1 = head;
    while (p1->next != NULL) {
        p1 = p1->next;
    }
    p1->next = p;
}

void print(struct student const *head) {
    if(head->next == NULL) {
        printf("the list is empty\n");
        return;
    }
    struct student *p = head->next;
    printf("this is the head\n");
    while (p != NULL) {
        printf("%s %s %d %d %s\n",p->sname,p->sno,p->sage,p->ssex,p->sclass);
        p = p->next;
    }
    printf("this is the end\n");
}

void del(struct student *head,char const *sno) {
    struct student *p1 = head,*p2 = head;
    if(p1->next == NULL) {
        printf("the list is empty\n");
        return;
    }
    while (p1 != NULL) {
        if (strcmp(p1->sno,sno) == 0) {
            if(p1 == head->next) {
                head->next = p1->next;
                p1->next = NULL;
            } else {
                p2->next = p1->next;
                p1->next = NULL;
            }
            free(p1);
            printf("delete success\n");
            return;
        }
        p2 = p1;
        p1 = p1->next;
    }
    printf("delete fail\n");
}

int main(void) {
    struct student *head = createHead(),*p1 = createNode("zhangsan","2019001",20,1,"class1"),*p2 = createNode("lisi","2019002",21,0,"class2"),*p3 = createNode("wangwu","2019003",22,1,"class3");
    insert(head,p1);
    insert(head,p2);
    insert(head,p3);
    print(head);
    del(head,"2019001");
    print(head);
    del(head,"2019002");
    del(head,"2019003");
    free(head);
    print(head);
    //free(p1);
    //free(p2);
    //free(p3);
    return 0;
}
