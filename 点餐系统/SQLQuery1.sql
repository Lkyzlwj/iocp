create database user_message
use user_message;
Create table Dinner_Table
(
	Table_ID char(3) not null ,
	Seat_Num int  not null,
	Table_Position varchar(20),
	Table_Situation varchar(10)
	Primary key(Table_ID)
); 

insert into Dinner_Table values('001',10,'��������','δʹ��');
insert into Dinner_Table values('002',8,'���ߵ�','δʹ��');
insert into Dinner_Table values('003',8,'����','δʹ��');
insert into Dinner_Table values('004',10,'��������','δʹ��');
insert into Dinner_Table values('005',8,'���ߵ�','δʹ��');
insert into Dinner_Table values('006',8,'����','δʹ��');
insert into Dinner_Table values('007',10,'��������','δʹ��');
insert into Dinner_Table values('008',8,'ˮ����','δʹ��');
insert into Dinner_Table values('009',4,'��ǧ��','δʹ��');
insert into Dinner_Table values('010',8,'ˮ����','δʹ��');
insert into Dinner_Table values('011',10,'��������','δʹ��');
insert into Dinner_Table values('012',4,'��ǧ��','δʹ��');
insert into Dinner_Table values('013',8,'ˮ����','δʹ��');
insert into Dinner_Table values('014',8,'��������','δʹ��');
insert into Dinner_Table values('015',8,'����','δʹ��');
insert into Dinner_Table values('016',10,'��������','δʹ��');
insert into Dinner_Table values('017',8,'ˮ����','δʹ��');
insert into Dinner_Table values('018',4,'��ǧ��','δʹ��');
insert into Dinner_Table values('019',4,'��ǧ��','δʹ��');
insert into Dinner_Table values('020',8,'����','δʹ��');

Create table Client
(
	Client_ID char(6) not null,--��000001��ʼ
	Table_ID char(3),
	Client_Message varchar(10) 
	Primary key(Client_ID),
	Foreign key(Table_ID) references Dinner_Table On delete cascade On update cascade 
);
insert into Client values('000001','001','');
insert into Client values('000002','002','');

Create table Dishes_List
(
	Dishes_ID char(6) not null ,  
	Dishes_Name varchar(20) not null,
	Dishes_Price int not null,
	Dishes_Classification varchar(10) not null,
	Primary key (Dishes_ID )
);
insert into Dishes_List values('100001','���м�',8,'��ɫ');
insert into Dishes_List values('100002','����±ˮѼ',12,'��ɫ');
insert into Dishes_List values('100003','����ǽ',20,'��ɫ');
insert into Dishes_List values('100004','¡�����',13,'��ɫ');
insert into Dishes_List values('100005','±��',8,'��ɫ');

insert into Dishes_List values('200001','���貤��',8,'����');
insert into Dishes_List values('200002','���躣��',5,'����');
insert into Dishes_List values('200003','����ƹ�',8,'����');
insert into Dishes_List values('200004','������빽',10,'����');
insert into Dishes_List values('200005','����źƬ',9,'����');

insert into Dishes_List values('300001','��������',12,'�Ȳ�');
insert into Dishes_List values('300002','�ع���',10,'�Ȳ�');
insert into Dishes_List values('300003','���Ŷ���',6,'�Ȳ�');
insert into Dishes_List values('300004','��������',8,'�Ȳ�');
insert into Dishes_List values('300005','������˿',8,'�Ȳ�');

insert into Dishes_List values('400001','������',10,'����');
insert into Dishes_List values('400002','����',8,'����');
insert into Dishes_List values('400003','������',9,'����');
insert into Dishes_List values('400004','�Ź���',10,'����');
insert into Dishes_List values('400005','�����',6,'����');

insert into Dishes_List values('500001','�׷�',1,'��ʳ');
insert into Dishes_List values('500002','������',2,'��ʳ');
insert into Dishes_List values('500003','���',2,'��ʳ');
insert into Dishes_List values('500004','���ݳ���',3,'��ʳ');
insert into Dishes_List values('500005','���������',5,'��ʳ');

insert into Dishes_List values('600001','��֭',3,'��ˮ');
insert into Dishes_List values('600002','�ջ���',1,'��ˮ');
insert into Dishes_List values('600003','����',15,'��ˮ');
insert into Dishes_List values('600004','�ɿڿ���',3,'��ˮ');
insert into Dishes_List values('600005','�齭ơ��',15,'��ˮ');

insert into Dishes_List values('700001','�������ȷ��ײ�',12,'�ײ�');
insert into Dishes_List values('700002','��ţ���ײ�',14,'�ײ�');
insert into Dishes_List values('700003','�����ײ�',10,'�ײ�');
insert into Dishes_List values('700004','�������Ƿ��ײ�',10,'�ײ�');
insert into Dishes_List values('700005','ԭ���������ײ�',11,'�ײ�');


Create table Bill 
(
	Bill_ID  char(6) not null ,--��200001��ʼ
	Client_ID char(6) not null,--���µ�����˵���ϲ�����������
	Dishes_ID char(6) not null, 
	Dishes_Name varchar(20) not null,
	Quantity int  not null,
	Price int,
	Foreign key(Client_ID ) references Client On delete cascade On update cascade,
	Foreign key(Dishes_ID) references Dishes_List On delete cascade On update cascade,
	Primary key(Bill_ID,Dishes_ID)
);




--------------------------------------------------------------------------------------------------------

Create table Department
(
	Department_ID char(6),--��100001��ʼ
	Department_Name varchar(10),
	Primary key(Department_ID)
);
insert into Department values('001','��ʦ��');
insert into Department values('002','����');
insert into Department values('003','�ɹ���');

Create table Employee
(
	Employee_ID char(11),
	Employee_Password varchar(6) not null,
	Employee_Name varchar(20),
	Employee_Sex char(2) check(Employee_Sex='��' or Employee_Sex='Ů'),
	Department_ID char(6),--��Ա����Ͳ���������ϲ�����������
	Employee_Style char(10), 
	Primary key(Employee_ID),
	Foreign key(Department_ID) references Department On delete cascade On update cascade 
);

insert into Employee values('20121003501','123456','����','Ů','002','����Ա');
insert into Employee values('20121003502','123456','����','Ů','002','����Ա');
insert into Employee values('20121003503','123456','����','��','002','����Ա');
insert into Employee values('20121003504','123456','����','Ů','002','����Ա');
insert into Employee values('20121003505','123456','����','��','002','����Ա');

insert into Employee values('20121003601','123456','����','Ů','003','�ɹ�Ա');
insert into Employee values('20121003602','123456','����','Ů','003','�ɹ�Ա');
insert into Employee values('20121003603','123456','����','��','003','�ɹ�Ա');
insert into Employee values('20121003604','123456','Ƥ��','Ů','003','�ɹ�Ա');
insert into Employee values('20121003605','123456','Ƥ��','��','003','�ɹ�Ա');

insert into Employee values('20121003701','123456','ɭ��','��','001','��ʦ');
insert into Employee values('20121003702','654321','����','��','001','��ʦ');
insert into Employee values('20121003703','123456','����','Ů','001','��ʦ��');
insert into Employee values('20121003704','123456','ѾѾ','Ů','001','��ʦ��');
insert into Employee values('20121003705','123456','����','��','001','��ʦ��');
insert into Employee values('20121003706','123456','ɭ��','��','001','��ʦ��');


Create table Purchase
(
	Goods_ID char(6),
	Employee_ID char(11),
	Goods_Name char(20),
	Goods_Quantity int,
	Purchase_Date char(10),
	Foreign key(Employee_ID) references Employee On delete cascade On update cascade,
	Primary key(Goods_ID)
);
insert into Purchase values('300001','20121003601','Ϻ',200,'2014-05-22');--Ϻ��
insert into Purchase values('300002','20121003602','����',200,'2014-05-22');--�����
insert into Purchase values('300003','20121003603','ţ��',200,'2014-05-22');--ţ���
insert into Purchase values('300004','20121003604','�Ͳ�',100,'2014-05-22');--�Ͳ˽�
insert into Purchase values('300005','20121003605','����',100,'2014-05-22');--������
insert into Purchase values('300006','20121003605','������',100,'2014-05-22');--��������
insert into Purchase values('300007','20121003604','����',100,'2014-05-22');--���˽�
insert into Purchase values('300008','20121003603','��',50,'2014-05-22');--��ֻ
insert into Purchase values('300009','20121003602','Ѽ',50,'2014-05-22');--Ѽֻ
insert into Purchase values('300010','20121003601','��',50,'2014-05-22');--��ֻ
insert into Purchase values('300011','20121003601','ľ��',150,'2014-05-22');--ľ�Ͻ�
insert into Purchase values('300012','20121003602','ݫ��',100,'2014-05-22');--ݫ���
insert into Purchase values('300013','20121003601','����',300,'2014-05-22');--������
insert into Purchase values('300014','20121003601','����',50,'2014-05-22');--�δ�
insert into Purchase values('300015','20121003603','³��������',20,'2014-05-22');--��Ͱ
insert into Purchase values('300016','20121003603','̩������',10,'2014-05-22');--�״�
insert into Purchase values('300017','20121003604','���',60,'2014-05-22');--��۴�
insert into Purchase values('300018','20121003604','̫̫�ּ���',10,'2014-05-22');--������
insert into Purchase values('300019','20121003604','���',60,'2014-05-22');--�����
insert into Purchase values('300020','20121003601','֥ʿ',60,'2014-05-22');--֥ʿ��
insert into Purchase values('300021','20121003601','���',100,'2014-05-22');--���ֻ
insert into Purchase values('300022','20121003601','�Ź�',200,'2014-05-22');--�Źǽ�
insert into Purchase values('300023','20121003601','��',60,'2014-05-22');--�ǽ�
insert into Purchase values('300024','20121003601','��',100,'2014-05-22');--���
insert into Purchase values('300025','20121003602','����',100,'2014-05-22');--������

Create table Goods
(
	Goods_ID char(6),--��300001��ʼ
	Goods_Name varchar(20),
	Goods_Price int,
	Foreign key(Goods_ID) references Purchase On delete cascade On update cascade,
	Primary key(Goods_ID)
);
insert into Goods values('300001','Ϻ',300);
insert into Goods values('300002','����',450);
insert into Goods values('300003','ţ��',300);
insert into Goods values('300004','�Ͳ�',100);
insert into Goods values('300005','����',150);
insert into Goods values('300006','������',150);
insert into Goods values('300007','����',150);
insert into Goods values('300008','��',250);
insert into Goods values('300009','Ѽ',240);
insert into Goods values('300010','��',300);
insert into Goods values('300011','ľ��',200);
insert into Goods values('300012','ݫ��',100);
insert into Goods values('300013','����',300);
insert into Goods values('300014','����',50);
insert into Goods values('300015','³��������',400);
insert into Goods values('300016','̩������',600);
insert into Goods values('300017','���',200);
insert into Goods values('300018','̫̫�ּ���',100);
insert into Goods values('300019','���',200);
insert into Goods values('300020','֥ʿ',300);
insert into Goods values('300021','���',350);
insert into Goods values('300022','�Ź�',200);
insert into Goods values('300023','��',100);
insert into Goods values('300024','��',250);
insert into Goods values('300025','����',250);














