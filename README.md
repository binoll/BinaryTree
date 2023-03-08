BINARY SEARCH TREE (БИНАРНОЕ ДЕРЕВО)
=========================

Описание:
-------------------------
**Двоичным деревом поиска (BST – binary search tree)** –  двоичное дерево, для которого выполняются 
следующие условия: 
1. Для любого узла его левое и правое поддеревья являются двоичными деревьями поиска; 
2. Значения, размещённые во всех узлах левого поддерева произвольного узла, меньше значения, размещённого в этом узле; 
3. Значения, размещённые во всех узлах правого поддерева произвольного узла, не меньше значения, размещённого в этом узле. 

![1.png](img%2F1.png)

Очевидно, данные в каждом узле дерева должны быть такого типа, для которого определена операция сравнения.
Для двоичного дерева поиска определены все операции, присущие двоичным деревьям. 
Реальное время выполнения операций зависит от формы дерева. 
Если оно вырождено и по форме близко к линейному связному списку, поиск потребует порядка n операций сравнения, 
если по форме ближе к полному дереву, то порядка log2n операций. 
Можно доказать, что при последовательном включении в дерево случайных данных среднее время выполнения 
операций оценивается величиной порядка log2n. Однако если входные данные при построении дерева
образуют упорядоченную последовательность, то формируется список, и все преимущества дерева будут утеряны.

Реализация:
-------------------------
**1. Включение элемента в дерево:** 
   1. Включение элемента k в двоичное дерево поиска происходит следующим образом: 
   2. Если дерево пусто, создаётся узел, который становится корнем дерева, и в него заносится значение включаемого элемента k. 2.	Если дерево не пусто, сравнивается значение k со значением, находящимся в корне дерева, и если k меньше, то включение производится в левое поддерево, иначе – в правое. Таким образом, включение нового элемента всегда происходит в лист дерева.

**2. Поиск в дереве:** 

Поиск узла с заданным значением осуществляется по пути предполагаемой его вставки. 
Искомый узел либо находится, либо нет (во втором случае достигается лист дерева с нулевыми указателями 
на правое и левое поддеревья, и поиск прекращается).

**3. Обход дерева:**
 
1. Сверху вниз – корень, левое поддерево, правое поддерево (КЛП); 
2. Слева направо (симметричный обход или обход «в глубину») – левое поддерево, корень, правое поддерево (ЛКП); 
3. Снизу вверх – левое поддерево, правое поддерево, корень (ЛПК). 

4. Другие три варианта (КПЛ, ПКЛ, ПЛК) симметричны первым трём. 
Процедура обхода рекурсивна. Под термином «обход дерева» понимается то, что в соответствии с одним из определённых 
выше вариантов посещается каждый узел дерева и с его содержательной частью выполняются некоторые действия.

**4. Удаление элемента:** 
1. Если узел является листом, он удаляется. 
2. Если узел имеет одного сына, узел удаляется, а его единственный сын становится сыном узла-отца (вместо удалённого узла). 
3. Если узел имеет двух сыновей, удаление осуществляют следующим образом. 
Для того чтобы не увеличивать высоту дерева, узел не удаляется, а его значение заменяется максимальным значением элемента из левого поддерева или минимальным из правого. В обоих случаях узел, из которого взято значение, имеет не более одного сына и удаляется в соответствии с вариантами 1 или 2.

Задание:
-------------------------
Описать шаблон классов двоичное дерево поиска (BinTree), представленное в виде 
многосвязного списка. Реализовать основные операции, осуществляемые с 
бинарными деревьями поиска: 
1. Создание бинарного дерева поиска; 
2. Вставка элемента в бинарное дерево поиска; 
3. Удаление элемента из бинарного дерево поиска; 
4. Поиск элемента в бинарном дереве поиска; 
5. Обход бинарного дерева поиска (указаны в варианте); 
6. Вывод бинарного дерева поиска; 
7. Проверка пустоты бинарного дерева поиска; 
8. Удаление бинарного дерева поиска.

Реализовать модульное тестирование методов и дружественных функций 
шаблона классов с помощью создания тестирующего проекта. Создать класс усечённый конус 
(элементы-данные: радиусы нижнего и верхнего оснований, высота конуса). Критерий сравнения: 
объём усечённого конуса. Обход бинарного дерева поиска: КПЛ(NRL), ЛКП(LNR).