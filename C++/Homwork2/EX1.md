四、写出一个将两个静态链表（属于同一个存储池）
合并的算法函数：
     void Merge(cursor M, cursor N); 
     合并的方法是将N链表中的所有结点添加到M链表
     的后面，并将N链表的表头结点添加到空闲结点链表中。
要求：1、定义静态链表的结点的结构以及结点的型SPACE
以及位置（position）和游标（cursor）的型。
	2、定义静态链表的基本操作：void Initialize();
     初始化，将所有存储池中的结点设置为空闲；
     cursor GetNode();
      从空闲链中获取一个结点；void FreeNode(cursor q); 
      将结点q加入到空闲链； void Insert 
      ( elementtype x, position p, cursor M ); 
      在链表M中的位置为p的元素后面添加一个值为x的结点；
      void Delete (cursor M,  position p );
       在链表M中删除位置为p的元素的后一个元素。