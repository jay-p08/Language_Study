# qt5로 만드는 투두 리스트
# 필요한 라이브러리 임포트
import sys
from PyQt5.QtWidgets import * # 모든 위젯 임포트
from PyQt5.QtCore import Qt # 코어 기능 임포트

# TodoList 클래스 정의
# QMainWindow를 상속받는다.
class TodoList(QMainWindow):
  def __init__(self):
    super().__init__() # 부모 클래스 초기화
    self.setWindowUI() # 메인 윈도우 제목, 크기 설정
    self.initUI_upper() # 할일 입력칸과 추가버튼 정의
    self.initUI_mid() # 추가된 할일 리스트를 출력
    self.initUI_bottom() # 할일 삭제/완료 버튼을 정의할 부분
  
  def initUI_mid(self):
    # 할일 목록을 표시할 리스트 위젯 생성
    self.task_list = QListWidget()
    # 메인 레이아웃에 할일 목록 위젯 추가
    self.main_layout.addWidget(self.task_list)


  def initUI_bottom(self):
    # 삭제 버튼 생성 및 클릭 이벤트 연결
    self.del_btn = QPushButton("삭제")
    # 버튼 클릭시 delete_task 메서드 호출
    self.del_btn.clicked.connect(self.delete_task) 
    self.main_layout.addWidget(self.del_btn)


  def setWindowUI(self):
    self.setWindowTitle("Todo List")
    self.setGeometry(300, 300, 400, 500)

  # UI 초기화 메서드 정의
  def initUI_upper(self):
    # 중앙 위젯 생성 및 설정
    self.center_widget = QWidget()
    self.setCentralWidget(self.center_widget)

    # 메인 수직 레이아웃 생성
    # 상단, 중단, 하단의 영역을 구분하기 위해
    # 수직으로 레이아웃을 구분한다.
    self.main_layout = QVBoxLayout(self.center_widget)

    # 할일 입력을 위한 수평 레이아웃 생성
    self.input_layout = QHBoxLayout()
    # 할일 입력을 위한 텍스트 입력창 생성
    self.task_input = QLineEdit() # 한 줄 텍스트 입력창
    # 어떤 내용을 입력할지 안내하기 위한
    # placeholder 텍스트 설정
    self.task_input.setPlaceholderText("할일을 입력하세요.")
    # 입력한 할일을 목록에 추가하기 위한 트리거(버튼)을 생성
    self.add_btn = QPushButton("추가")
    # 버튼 클릭시 add_task 메서드 실행
    self.add_btn.clicked.connect(self.add_task)

    # 입력창과 추가 버튼을 수평 레이아웃에 추가
    self.input_layout.addWidget(self.task_input)
    self.input_layout.addWidget(self.add_btn)

    # 입력창이 있는 레이아웃을 메인 레이아웃에 추가
    self.main_layout.addLayout(self.input_layout)

  # 추가 버튼을 눌렀을 때, 할일 내용을 할일 목록에 추가하는 기능
  def add_task(self):
    # 입력창에서 텍스트를 가져오기
    task = self.task_input.text()
    # 만약 task가 비어있지 않다면
    if task:
      # 새로운 할일 항목 생성
      item = QListWidgetItem(task)
      # 체크박스 기능
      item.setFlags(item.flags() | Qt.ItemFlag.ItemIsUserCheckable)
      # 초기 상태는 체크 해제
      item.setCheckState(Qt.CheckState.Unchecked)
      # 리스트에 항목 추가
      # self.task_list.addItem(item) # 목록의 아래에 아이템 추가
      self.task_list.insertItem(0, item) # 목록의 위에 아이템 추가

      # 입력창 비우기
      self.task_input.clear()
    else:
      # task 내용이 비어있을 경우
      # "내용을 입력해주세요" 경고창띄우기(추가)
      pass

  # 삭제 버튼을 눌렀을 때, 선택할 할일을 목록에서 삭제
  def delete_task(self):
    # 삭제할 항목들을 저장할 빈 리스트 생성
    items_to_remove = []
    # 체크한 항목들을 리스트에 담아 삭제
    # 모든 항목을 순회하면서 체크된 항목 찾기
    for i in range(self.task_list.count()):
      # 0부터 task_list의 개수-1번째까지 인덱스를 i에 담는다.
      # task_list의 i번째 행 아이템을 가져온다.
      item = self.task_list.item(i)
      # 체크가 되어 있다면
      if item.checkState() == Qt.CheckState.Checked:
        items_to_remove.append(item)
    
    # 체크된 항목들을 삭제
    for item in items_to_remove:
      self.task_list.takeItem(self.task_list.row(item))

if __name__ == "__main__":
  app = QApplication(sys.argv)
  todo_list = TodoList() # 인스턴스 생성
  todo_list.show() # 윈도우 표시
  sys.exit(app.exec_())