#define QUEUE_SIZE 5
struct queue
{
    int array[QUEUE_SIZE]; // �f�[�^������z��
    int wp;                // ���Ƀf�[�^������ꏊ�̔z��ԍ�
    int quantity;          // �f�[�^�̌�
};

int enqueue(struct queue *obj, int data)
{
    // �c��̈悪���邩�m�F����D
    // �f�[�^�����R�����m�F����D
    // �z��Ƀf�[�^��ۑ�����D
    // �ŐV�̃f�[�^���������ꏊ�̎��̏ꏊ���w���悤�ɒl���X�V����D
    // �f�[�^�̌��J�E���g�𑝂₷�D
    // �Ԃ�l��Ԃ��D
    if (obj->quantity >= QUEUE_SIZE)
    {
        return -101;
    }
    if (data < 0)
    {
        return -102;
    }
    obj->array[obj->wp] = data;
    obj->wp = (obj->wp + 1) % QUEUE_SIZE;
    obj->quantity++;
    return -100;
}
int dequeue(struct queue *obj)
{
    // �f�[�^�����݂��邩�ǂ����m�F����D
    // �L���[����f�[�^���Ƃ肾���D
    // �f�[�^�̌��̃J�E���g�����炷�D
    // �f�[�^�������͕Ԃ�l��Ԃ��D
    if (obj->quantity <= 0)
    {
        return -201;
    }
    int data = obj->array[0];
    obj->quantity--;
    obj->array[(obj->wp+QUEUE_SIZE - obj->quantity - 1) % QUEUE_SIZE] = 0;
    return data;
}
int initqueue(struct queue *obj)
{
    // �L���[�̃f�[�^������z������ׂ� 0 �ɏ���������D
    // �L���[�̃f�[�^�i�[���� 0 �ɏ���������
    // �L���[�� wp �|�C���^�� 0 �ɏ���������D
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        obj->array[i] = 0;
    }
    obj->quantity = 0;
    obj->wp = 0;
    return 0;
}
int showQueue(struct queue *obj)
{
    // �z��S�̂̃f�[�^�����ɕ\������D
    // �f�[�^�ƃf�[�^�̊Ԃɋ�؂蕶���u|�v��\������D
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        printf("%d", obj->array[i]);
        if (i < QUEUE_SIZE - 1)
        {
            printf("|");
        }
    }
    return 0;
}
void showResult(int result)
{
    // result �̒l�ɉ����āC�Ή�����G���[���b�Z�[�W��\������D
    switch (result)
    {
    case -100:
        printf("����I��\n");
        break;
    case -101:

        printf("�G���[�F�L���[�����t�ł�\n");
        break;
    case -102:
        printf("�G���[�F�f�[�^�����R���ł͂���܂���\n");
        break;
    case -201:
        printf("�G���[�F�L���[����ł�\n");
        break;
    default:
        printf("\n");
        break;
    }
}

int main(void)
{
    
    struct queue obj;
    int result;
    initqueue(&obj);
    result = enqueue(&obj,40);
    showQueue(&obj);
    printf("<40");
    showResult(result);
    result = enqueue(&obj,60);
    showQueue(&obj);
    printf("<60");
    showResult(result);
    result = enqueue(&obj,10);
    showQueue(&obj);
    printf("<10");
    showResult(result);
    result = enqueue(&obj,80);
    showQueue(&obj);
    printf("<80");
    showResult(result);
    result = enqueue(&obj,30);
    showQueue(&obj);
    printf("<30");
    showResult(result);
    result = enqueue(&obj,50);
    showQueue(&obj);
    printf("<50");
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = enqueue(&obj,1);
    showQueue(&obj);
    printf("<1");
    showResult(result);
    result = enqueue(&obj,2);
    showQueue(&obj);
    printf("<2");
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = enqueue(&obj,200);
    showQueue(&obj);
    printf("<200");
    showResult(result);
    result = enqueue(&obj,300);
    showQueue(&obj);
    printf("<300");
    showResult(result);
    result = enqueue(&obj,-400);
    showQueue(&obj);
    printf("<-400");
    showResult(result);
    result = enqueue(&obj,500);
    showQueue(&obj);
    printf("<500");
    showResult(result);
    return 0;
}