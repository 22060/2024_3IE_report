#include <malloc.h>
#include <stdio.h>
// �f�[�^�Ǝ��̃L���[�̃A�h���X���w���\���̂̐錾
struct queue
{
    int val;
    struct queue *addr;
};
struct queue *bottom_queue = NULL; // �ŌẪL���[�̃A�h���X���L�����Ă����|�C���^
struct queue *top_queue = NULL;    // �ŐV�̃L���[�̃A�h���X���L�����Ă����|�C���^
int enqueue(int data)
{
    int r_val = -100;                            // �Ԃ�l��錾����
    struct queue *new_queue;                     // �V�����m�ۂ���̈�i�\���́j�ւ̃|�C���^��錾����
    if (data < 0 /*�}������f�[�^�� 0 �ȉ��ł������Ƃ�*/) // 0 �ȉ��̃f�[�^�����͂��ꂽ��
    {
        r_val = -102; // �Ԃ�l��ݒ肷��
    }
    // �ǉ�����̈���m�ۂ���
    /*malloc �ō\���̂̃I�u�W�F�N�g�̗̈���m�ۂ��āC�m�ێ��s������*/
    else if ((new_queue = (struct queue *)malloc(sizeof(struct queue))) == NULL)
    {
        // �m�ۂł��Ȃ������Ƃ�
        r_val = -101;
    }
    else
    {
        // �V�����L���[�̃f�[�^�l�Ƃ��Ĉ����̃f�[�^������(enqueue:2-1)
        new_queue->val = data;
        // �V�����L���[�̃A�h���X�l�Ƃ��� NULL ������(enqueue:2-2)
        new_queue->addr = NULL;
        // �܂� 1 �̃L���[���Ȃ���
        if (bottom_queue == NULL)
        {
            // �V�����L���[���ŌÂł���̂ŁC�ŌẪL���[���w���A�h���X���X�V����(enqueue:4-1)
            bottom_queue = new_queue;
            // �V�����L���[���ŐV�ł���̂ŁC�ŐV�̃L���[���w���A�h���X���X�V����(enqueue:4-2)
            top_queue = new_queue;
        }
        // 1 �ȏ�̃L���[������Ƃ�
        else
        {
            // ����܂ōŐV�������̈�ɐV�����̈��A������(enqueue:3-1)
            top_queue->addr = new_queue;
            // �V�����̈悪�ŐV�ł���̂ŁC�ŐV���w���A�h���X�ɑ������(enqueue:3-2)
            top_queue = new_queue;

        }
        r_val = 0;
    }

    return r_val;
}
int dequeue()
{
    int r_val = -200;         // �Ԃ�l������ϐ����m�ۂ���
    struct queue *new_bottom; // �V���ɍŌÂɂȂ�̈���w���|�C���^��錾����
    // �c��L���[�� 1 �̏ꍇ
    if (top_queue == bottom_queue && bottom_queue != NULL)
    {
        // �ŌẪf�[�^��Ԃ�l�ɂ��邽�߂Ɏ��o��(dequeue:1-1)
        // �f�[�^�����o������̃L���[���������(dequeue:1-2)
        // �ŐV�̃L���[���Ȃ����Ƃ�錾����(dequeue:1-3)
        // �ŌẪL���[���Ȃ����Ƃ�錾����(dequeue:1-4)
        r_val = bottom_queue->val;
        free(bottom_queue);
        top_queue = NULL;
        bottom_queue = NULL;
        
    }
    // �c��̃L���[�� 2 �ȏ�̏ꍇ
    else if (top_queue != NULL && bottom_queue != NULL)
    {
        // �ŌẪf�[�^��Ԃ�l�ɂ��邽�߂Ɏ��o��(dequeue:2-1)
        // �V���ɍŌÂɂȂ�L���[�̃A�h���X���o���Ă���(dequeue:2-2)
        // �f�[�^�����o������̃L���[���������(dequeue:2-3)
        // �V���ɍŌẪL���[�ɂȂ�A�h���X���X�V����(dequeue:2-4)
        r_val = bottom_queue->val;
        new_bottom = bottom_queue->addr;
        free(bottom_queue);
        bottom_queue = new_bottom;
    }
    // �L���[�����ɋ���ۂ̏ꍇ
    else if (bottom_queue == NULL)
    {
        r_val = -201;
    }
    // �\�������Ȃ��G���[
    else
    {
        r_val = -202;
    }
    return r_val;
}
int showQueue()
{
    // ���X�g�S�̂̃f�[�^�����ɕ\������D
    // �f�[�^�ƃf�[�^�̊Ԃɋ�؂蕶���u|�v��\������D
    struct queue *this_queue = bottom_queue;
    while (this_queue != NULL)
    {
        printf("%d|", this_queue->val);
        this_queue = this_queue->addr;
    }
}
void showResult(int result)
{
    // result �̒l�ɉ����āC�Ή�����G���[���b�Z�[�W��\������D
    switch (result)
    {
    case -100:
        printf("�G���[�F�}������f�[�^�� 0 �ȉ��ł��D\n");
        break;
    case -101:
        printf("�G���[�F�������̊m�ۂɎ��s���܂����D\n");
        break;
    case -102:
        printf("�G���[�F�}������f�[�^�� 0 �ȉ��ł��D\n");
        break;
    case -200:
        printf("�G���[�F�L���[����ł��D\n");
        break;
    case -201:
        printf("�G���[�F�L���[����ł��D\n");
        break;
    case -202:
        printf("�G���[�F�\�����Ȃ��G���[���������܂����D\n");
        break;
    default:
        printf("\n");
        break;
    }
}
void freeQueue()
{
    struct queue *this_queue;
    while (bottom_queue != NULL)
    {
        // ����J���������L���[�̃A�h���X���擾
        // �����ɍŌÂɂȂ�L���[�̃A�h���X���X�V
        // �L���[�̗̈���������
        this_queue = bottom_queue;
        bottom_queue = bottom_queue->addr;
        free(this_queue);
    }
}
int main()
{
    int result;
    result = enqueue(40);
    showQueue();
    printf("<40");
    showResult(result);
    result = enqueue(60);
    showQueue();
    printf("<60");
    showResult(result);
    result = enqueue(10);
    showQueue();
    printf("<10");
    showResult(result);
    result = enqueue(80);
    showQueue();
    printf("<80");
    showResult(result);
    result = enqueue(30);
    showQueue();
    printf("<30");
    showResult(result);
    result = enqueue(50);
    showQueue();
    printf("<50");
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = enqueue(1);
    showQueue();
    printf("<1");
    showResult(result);
    result = enqueue(2);
    showQueue();
    printf("<2");
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = enqueue(200);
    showQueue();
    printf("<200");
    showResult(result);
    result = enqueue(300);
    showQueue();
    printf("<300");
    showResult(result);
    result = enqueue(-400);
    showQueue();
    printf("<-400");
    showResult(result);
    result = enqueue(500);
    showQueue();
    printf("<500");
    showResult(result);
    freeQueue();

    return 0;
}