#define PROGRAM2
#ifdef PROGRAM1//�ۑ�1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  FILE* wfp; // �������ݗp�t�@�C���̃|�C���^�ϐ�
  char input[100] = "y\0";
  int ch;
  if ((argc == 3) && (strcmp(argv[1], "-i") == 0)) {
    wfp = fopen(argv[2], "r+");
    if (wfp == NULL)
    {
      wfp = fopen(argv[2], "wb");
    }
    else {
      printf("%s�㏑�����Ă悢�ł���?[Y/N]", argv[2]);
      do
      {
      loop:
        ch = getchar();
        if (getchar() != '\n') {
          goto loop;
        }
      } while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
      if (ch == 'n' || ch == 'N') {
        fclose(wfp);
        return -1;
      }
    }
  }
  else if ((argc == 2) && (strcmp(argv[1], "-i") != 0)) {
    if ((wfp = fopen(argv[1], "wb")) == NULL)
    {
      printf("Error occurs\n");
      return -1;
    }
  }
  else {
    printf("Usage: [-i] file1\n");
    return -1;
  }
  while (strcmp(input, "Y\0") == 0 || strcmp(input, "y\0") == 0)
  {
    printf("��������͂��Ă�������\n");
    scanf("%s", input);
    fprintf(wfp, "%s\n", input);
    while (strcmp(input, "Y\0") != 0 && strcmp(input, "y\0") != 0 && strcmp(input, "N\0") != 0 && strcmp(input, "n\0") != 0)
    {
      printf("���͂𑱂��܂���?[Y/N]");
      scanf("%s", input);
    }
  }
  fclose(wfp);
  return 0;
}
#endif // PROGRAM61
#ifdef PROGRAM2 //�ۑ�2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  srand((uint16_t)time(NULL));
  FILE* rfp; // �ǂݍ��ݗp�t�@�C���̃|�C���^�ϐ�
  int ch; // �t�@�C������ǂݍ���1�o�C�g�̃f�[�^
  int count = 0;
  int j = 0;
  if (argc != 3) {
    printf("Usage: random file1 count\n");
    return -1;
  }
  if ((rfp = fopen(argv[1], "wb")) == NULL)
  {
    printf("Error occurs\n");
    return -1;
  }
  count = atoi(argv[2]);
  for (int i = 0; i < count; i++)
  {
    int ran = rand() % 1000;
    if ((ran % 111) == 0) {
      j++;
      fprintf(rfp, "%3d %s \n", ran, "������");
    }
    else {
      fprintf(rfp, "%3d %s \n", ran, "�͂���");
    }
  }
  fprintf(rfp, "���s��: %d, �������: %d, ���Ғl: 1.000000[%%], �m��: %f[%%]",count,j, (double)j / (double)count * 100);
  printf("%f\n", (double)j / (double)count * 100);
  printf("%d", j);
  fclose(rfp);
  return 0;
}
#endif // PROGRAM3
