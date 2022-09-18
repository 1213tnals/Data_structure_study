## Data_structure_study

1. :star:**연결리스트** :  
배열을 이용했을 때보다 삽입과 삭제가 많은 경우 효율적 / 인덱스에 바로 참조해야할 경우 배열이 더 효율적
2. **양방향 연결리스트** :  
(이 코드는 오름차순으로 정렬하기 위한 양방향 연결리스트임)
3. **스택** :  
한쪽으로 들어가서 한쪽으로 나오는 구조
4. **큐** :  
뒤로 들어가서 앞으로 나오는 구조
5. **선택정렬** :  
가장 작은 것을 선택해서 앞으로 보내는 정렬기법, 가장 작은 것을 선택하는 데에 N번, 앞으로 보내는 데에 N번의 연산으로 O(N^2)의 시간 복잡도를 가짐
5. **삽입정렬** :  
삽입할 때 적절한 위치에. 들어갈 위치 선택 N번, 선택하는 횟수 N번. O(N^2)
6. **퀵정렬** :  
피벗을 기준으로 큰 값과 작은 값을 서로 교체하는 정렬 기법, 교체 N번, 교체 이후 원소가 반으로 나누어지므로 원소 나누는데 logN번(완전이진트리). 즉 O(NlogN).
왼쪽에서부터 큰 값 찾고 오른쪽에서부터 작은 값 찾음. 작은 값이 오른쪽에 있으면 두 값을 교차 / 작은 값이 왼쪽에 있으면 피벗값과 찾은 값을 비교 후 처리. 나누어진 2개에서 다시 퀵정렬 실행
7. **계수정렬**:  
크기를 기준으로 데이터의 개수를 세는 정렬 알고리즘. 각 데이터를 바로 크기를 기준으로 분류. O(N). 데이터의 크기가 한정적일 때 사용.  
ex)00410201 -> 00001124

8. **기수정렬**:  
자릿수를 기준으로 차례대로 데이터를 정렬하는 알고리즘. 가장 큰 자릿수가 D일 때, O(DN)

9. **이진트리**:  
포인터를 이용해서 구현할 수 있음. 데이터를 방문하기 위해서 순회 알고리즘을 효과적으로 사용할 수 있음.

10. **우선순위 큐**:  
완전 이진트리형태의 힙을 이용해 구현. 큐의 삽입과 삭제 - O(logN), 정렬 - O(NlogN)
우선순위를 가진 데이터들을 저장하는 큐. 데이터를 꺼낼 때 우선 순위가 높은 데이터가 가장 먼저 나옴. 운영체제 기술에서 적용. 트리구조.
최대힙(부모노드가 자식노드보다 큰 값 가짐)을 이용해 구현.

11. **순차탐색**:  
특정한 원소를 찾기 위해서 원소를 순차적으로 하나씩 탐색하는 방법. O(N)

11. :star:**이진탐색**:  
이미 정렬 되어있는 상황에서 사용가능한 알고리즘. 탐색 범위를 절반씩 좁혀가며 데이터를 탐색. O(logN)

12. **인접 행렬**:  
모든 정점들의 연결 여부를 저장하여 O(V^2)의 공간을 요구하므로 공간 효율성이 떨어지지만, 두 정점이 서로 연결되어 있는지 확인하기 위해서 O(1)의 시간을 요구

12. **인접 리스트**:  
연결된 간선의 정보만을 저장하여 O(E)의 공간을 요구하므로 공간 효율성은 우수하지만, 두 정점이 서로 연결되어 있는지 확인하기 위해 O(V)의 시간을 요구

13. **깊이 우선탐색(DFS)**:  
깊은 것을 우선적으로 탐색하는 알고리즘. 전체 노드를 탐색하고자 할 때 사용. 스택 자료구조에 기초. O(N)

14. **너비 우선탐색(BFS)**:  
너비를 우선으로 하여 탐색하는 알고리즘. 전체 노드를 탐색하고자 할 때 사용. 큐 자료구조에 기초. O(N). 깊이보다 수행시간 좋음

15. :star:**이진 탐색 트리**:  
한번 확인할 때마다 보아야 하는 원소의 갯수가 절반씩 줄어듦. 완전 이진트리인 경우 O(logN)
이진 탐색 트리는 항상 부모의 노드가 왼쪽 자식보다는 크고 오른쪽 자식보다는 작으므로, 찾고자 하는 값이 부모 노드보다 작을 경우 왼쪽 자식으로, 클 경우 오른쪽 자식으로 이어나가면서 방문
(트리를 만들 때는 트리의 균형이 맞도록 설정하는 것이 중요)

16. **AVL트리**:  
균형이 갖춰진 이진 트리. 균형인수(|왼쪽자식높이-오른쪽자식높이|) 개념을 이용. 모든 노드에 대한 균형인수가 +1, 0, -1인 트리. 아닐 경우 회전을 통해 트리를 재구성
AVL트리의 균형 잡기는 각 노드가 삽입 될 때마다 수행되어야함. 삽입 과정에서 소요되는 시간 복잡도: O(logN).
편향 이진트리의 경우 O(N)이지만 AVL트리는 탐색에 있어 항상 O(logN)을 유지
