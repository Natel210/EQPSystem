# Shared_Library

## <a id="����" ></a>0. ����
> 1. <a href="#����" style="color: dimgray;">����</a>
> 2. <a href="#export-����Ʈ" style="color: dimgray;">Export ����Ʈ</a>
> 3. <a href="#�ڵ�-�ۼ�-��Ģ" style="color: dimgray;">�ڵ� �ۼ� ��Ģ</a>
> 4. <a href="#�ش�-����-�ۼ�-��Ģ" style="color: dimgray;">�ش� ���� �ۼ� ��Ģ</a>
> 5. <a href="#�ڵ�-����" style="color: dimgray;">�ڵ� ����</a>
> 6. <a href="#����-����" style="color: dimgray;">���� ����</a>

## <a id="����"></a>1. ���� <a href="#����" style="color: dimgray;">��</a>
> - ��Ī : ���� ���� ���� ���̺귯��
> - �뵵 : �ַ�� ������Ʈ ������ ���� ���� ���̺귯��
> - ���� : v1.0.0.0

## <a id="export-����Ʈ"></a>2. Export ����Ʈ <a href="#����" style="color: dimgray;">��</a>
> -  ���� ���̺귯��

## <a id="�ڵ�-�ۼ�-��Ģ"></a>3. �ڵ� �ۼ� ��Ģ <a href="#����" style="color: dimgray;">��</a>
### <a id="�ڵ�ǥ���" ></a> A. ǥ��� <a href="#�ڵ�-�ۼ�-��Ģ" style="color: dimgray;">��</a>
> - �⺻ ������ �ܾ�� �ܾ �ռ��� ��� <code>������ũ ǥ���</code> ��� 
> - ���� �����̽� <a href="#�ڵ�ǥ���" style="color: dimgray;">��</a>
>    > - <code>ī�� ǥ���</code>
>    > - <code>�����</code> �ۼ� ����
> - Ŭ���� <a href="#�ڵ�ǥ���" style="color: dimgray;">��</a>
>    > - <code>�Ľ�Į ǥ���</code>
>    > - <code>�����</code> �ۼ� ����
> - ����ü(<code>struct</code>) <a href="#�ڵ�ǥ���" style="color: dimgray;">��</a>
>    > - <code>�Ľ�Į ǥ���</code>
>    > - ���λ� <code>_tag</code> ��� ����
>    > - <code>table</code>�� ���� �ܾ� �������� ����ü��� ���� ��Ȯ�ϰ� �� �� �ֵ��� ��
>    > - <code>�����</code> �ۼ� ����
> - �̳�(<code>enum</code>) <a href="#�ڵ�ǥ���" style="color: dimgray;">��</a>
>    > - ���λ� <code>E</code>�� ����  <code>�Ľ�Į ǥ���</code>
>    > - <code>�����</code> �ۼ� ����
> - �Լ� <a href="#�ڵ�ǥ���" style="color: dimgray;">��</a>
>    > - <code>������ũ ǥ���</code>
>    > - <code>������</code> �ۼ� ����
> - <a id="�ڵ�ǥ���-��ü" ></a> ��ü <a href="#�ڵ�ǥ���" style="color: dimgray;">��</a>
>    > - <code>ī�� ǥ���</code>
>    > - <code>�����</code> �ۼ� ����
>    > - <code>is</code>, <code>check</code>, <code>cal</code> ���� �������� ��� �ܾ� ��� ���� <a href="#�ڵ�ǥ���-��ü" style="color: dimgray;">��</a>
>    >    > - �ش� �ܾ� ���� �տ� ����� �� �ֵ��� ��.
>    > - �ɹ� ���� (class ����) <a href="#�ڵ�ǥ���-��ü" style="color: dimgray;">��</a>
>    >    > - <code>private</code>�� ���  <code>_</code> ���λ� ����
>    > - ���� ���� (�Լ� ���� ���� ����) <a href="#�ڵ�ǥ���-��ü" style="color: dimgray;">��</a>
>    >    > - ���λ� <code>temp</code> ��� ����
>    > - ���� ���� (static �Ǵ� c ��Ÿ�� ����) <a href="#�ڵ�ǥ���-��ü" style="color: dimgray;">��</a>
>    >    > - ���λ� <code>g_</code> ��� ����
>    > - ��� <a href="#�ڵ�ǥ���-��ü" style="color: dimgray;">��</a>
>    >    > - <code>constexpr</code> ���
>    >    > - ���� �������� ���� �ÿ��� ���� �Լ��� ����ϰ� �ش��� ���Ͼ� �ʱ�ȭ�� �� ��
>    >    > - �ش� ������ �Ұ����� ��쿡�� <code>static</code> ���� ��밡��
>    > - �Լ� ��ü <a href="#�ڵ�ǥ���-��ü" style="color: dimgray;">��</a>
>    >    > - ������ ���� ���

### B. �ۼ� ��Ģ <a href="#�ڵ�-�ۼ�-��Ģ" style="color: dimgray;">��</a>
> - Ŭ������ ��쿡�� Ŭ���� ��� ���� ���� ���ƾ���
> - ������ ������ �°� ���� �ʼ�
> - <code>pulbic</code> <code>static</code> ���� ��� ����
>    > - ������ ���ϰ� ���� Ư��ȭ ��� ����
> - <code>enum</code> ��� <code>enum class</code>�� ���, �ε����� ��� ���
> - Get �Լ� : <code>[[nodiscard]]</code>�� ���� ��
> - <code>Pointer</code>�� <code>std::</code><code>shared_ptr</code>, <code>std::</code><code>weak_ptr</code> ���, <code>dll export</code>�ÿ��� �Ϲ� ������(<code>*</code>) ���

## <a id="�ش�-����-�ۼ�-��Ģ"></a>4. �ش� ���� �ۼ� ��Ģ <a href="#����" style="color: dimgray;">��</a>
### A. ���� ���� <a href="#�ش�-����-�ۼ�-��Ģ" style="color: dimgray;">��</a>
> - <code>0000000</code> �ڽ��� �����Ǵ� ������ �̸�
> - <code>0000000</code><code>.cpp</code>�� �߰��Ǵ� �ڽ� Ŭ���� �ش� (<code>0000000</code><code>.h</code>)�� �ش����带 ��������
<br/>

### B. ���λ� <a href="#�ش�-����-�ۼ�-��Ģ" style="color: dimgray;">��</a>
> - ��� ���� �� : <code>DECLARE_SHARED_LIBRARY_</code><code>0000000</code>
> - STD ��� �� : <code>USE_STD_</code><code>0000000</code>
> - ���� Code ��� �� : <code>USE_SHARED_LIBRARY</code><code>0000000</code>
<br/>

### C. ���̻� <a href="#�ش�-����-�ۼ�-��Ģ" style="color: dimgray;">��</a>
> - �ش��� �ִ� ��� : <code>���λ�</code><code>0000000</code>
> - �ش��� CPP�� �����ִ°��
>    > - <code>.h</code> : <code>���λ�</code><code>0000000</code><code>_H</code>
>    > - <code>.cpp</code> : <code>���λ�</code><code>0000000</code><code>_CPP</code>
<br/>

## <a id="�ڵ�-����">5. �ڵ� ���� <a href="#����" style="color: dimgray;">��</a>

## <a id="����-����">6. ���� ���� <a href="#����" style="color: dimgray;">��</a>

<!-- v1.0.0.0 -->
<details close>
<summary style="font-size: 17.5px;">v1.0.0.0 <a href="#����-����" style="color: dimgray;">��</a></summary>
<div>

> - ���� ����
</div>
</details> 