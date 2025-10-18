from flask import Flask, request, render_template_string
from datetime import datetime

app = Flask(__name__)

@app.route('/track')
def track():
    ip = request.headers.get('X-Forwarded-For', request.remote_addr)
    user_agent = request.headers.get('User-Agent')
    now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    print(f"[{now}] IP: {ip}, User-Agent: {user_agent}")
    
    to_url = request.args.get('to', 'https://naver.com')

    # 중간 HTML로 자동 리디렉션
    return render_template_string(f"""
        <html>
        <head>
            <meta http-equiv="refresh" content="0; url={to_url}">
        </head>
        <body>
            Redirecting...
        </body>
        </html>
    """)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
# https://6a48-2a09-bac5-4732-1a14-00-299-45.ngrok-free.app/?to=https://naver.com