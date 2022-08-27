# 다운 받은 파일 복사 프로그램
# 2022203036 소프트웨어학부 임동건
import os
import time
import shutil
from tkinter import filedialog
from tkinter import *
# 컴퓨터 내에 watchdog 모듈이 없을 경우 자동설치
try:
    from watchdog.observers import Observer
    from watchdog.events import FileSystemEventHandler
except ModuleNotFoundError as e:
    print(e)
    os.system("pip install watchdog")


class Watcher:

    # 클래스 Watcher 생성자
    def __init__(self, path):
        self.event_handler = None
        self.observer = Observer()  # Observer 객체 생성
        self.target_directory = path  # 감시 대상 경로 지정

    def run(self):
        self.event_handler = Handler()  # 이벤트 처리 Handler 객체 생성
        self.observer.schedule(self.event_handler, self.target_directory, recursive=False)
        self.observer.start()  # 해당 directory 모니터링 시작

        try:
            while True:
                time.sleep(2)  # 2초 간격으로 대상 디렉토리 감시

        except KeyboardInterrupt as cz:  # ctrl+z 입력시 감시 종료
            self.observer.stop()
            print(cz)
            print("감시 종료")


class Handler(FileSystemEventHandler):

    # 메서드 재정의
    def on_moved(self, event):  # 파일 이동 시
        print("파일이 성공적으로 이동되었습니다.")

    def on_created(self, event):  # 파일 생성 시
        print(event.src_path)
        file_ext = os.path.splitext(os.path.basename(event.src_path))[0]  # 인식된 파일의 파일명과 확장자 정보 추출(문자열)
        filename = file_ext.split(".")[0]  # 위 file_ext 의 파일명 부분 추출
        ext = file_ext.split(".")[1]  # 위 file_ext 의 파일명 부분 추출

        if ext in f_ext:  # 저장할 확장자 디렉토리 리스트 내 해당 확장자가 있을 경우
            print("해당 확장자 폴더를 인식하였습니다.")
        else:
            f_ext.append(ext)
            os.mkdir(save_dir + "/" + ext)  # 해당 확장자 디렉토리 생성

        revise_filename(filename)
        r_file_ext = rfname + "." + ext  # 변경된 파일 명으로 변경
        shutil.copy(kakao + "/" + file_ext, save_dir + "/" + ext + "/" + r_file_ext)


def revise_filename(f_name):  # 사용자 입력 받아 파일명 변경 함수(gui 구현)
    wrt = Tk()  # tkinter 창 생성
    wrt.title('파일 이름 변경')
    wrt.geometry('350x150+500+200')
    lab1 = Label(wrt, text='수정후 Enter키 입력')
    lab1.pack()
    ent_name = Entry(wrt, width=40)  # tkinter 입력 블럭 생성
    ent_name.insert(0, f_name)  # 기존 파일 명 입력
    ent_name.pack()

    def btn_cmd(event):  # entry 창 이벤트 함수
        global rfname
        rfname = str(ent_name.get())  # 사용자에게 입력받은 문자열 저장
        wrt.destroy()

    def close_wrt():  # 윈도우 창에서 x버튼 눌렀을 때 이벤트 함수
        wrt.destroy()

    ent_name.bind('<Return>', btn_cmd)  # enter키 입력시 이벤트 처리
    wrt.protocol('WM_DELETE_WINDOW', close_wrt)  # 윈도우 창 닫을시 이벤트 처리
    wrt.mainloop()


# 메인 함수
# 기본 폴더 생성(확장자 정보는 리스트 형태로)
# 기본 폴더가 있을 시 생략
if __name__ == "__main__":
    kakao = os.path.expanduser('~/Documents/카카오톡 받은 파일')  # 카카오톡 받은 파일 경로 저장($Home 처리)
    save_dir = filedialog.askdirectory(title='저장할 폴더 선택')  # 윈도우 폴더 지정 gui를 이용해 경로 저장

    if kakao == "" or save_dir == "":  # 폴더 지정을 안했을 시
        exit()

    f_ext = ['jpg', 'png', 'mp4', 'pdf', 'hwp', 'mp3'] # 확장자 디렉토리 생성을 위한 리스트 생성

    window = Tk()  # tkinter 창 생성
    window.title('초기 설정')
    window.geometry("350x150+500+200")
    label = Label(window, text='초기 설정을 해주세요.')
    label.pack()

    def yes_call():  # '네' 버튼 이벤트 함수
        for i in range(len(f_ext)):
            os.mkdir(save_dir + "/" + f_ext[i])
        window.destroy()

    def close_window():  # '이미 설정했습니다.' 버튼 이벤트 함수
        window.destroy()

    def close_program():  # '프로그램 종료' 버튼 이벤트 함수
        window.destroy()
        print('프로그램을 종료합니다')
        exit()
    # tkinter 창 버튼 클릭시 이벤트 처리
    b1 = Button(window, text='네', command=yes_call, width=3)
    b2 = Button(window, text='이미 설정했습니다.', command=close_window, width=15, height=1)
    b3 = Button(window, text='프로그램 종료', command=close_program, width=15)
    window.protocol('WM_DELETE_WINDOW', close_window)  # tkinter 창 닫을 시 이벤트 처리
    b1.pack()
    b2.pack()
    b3.pack()
    window.mainloop()

    os.chdir(kakao) # 작업 환경 지정
    w = Watcher(kakao)  # 메인 함수에서의 Watcher 객체 생성자
    w.run()
