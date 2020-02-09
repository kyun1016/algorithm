from selenium import webdriver
import os
import firebase_admin
from firebase_admin import credentials, firestore

# 셀레니움으로 공지사항 정보 추출 후 DB 업로드
def lambda_handler(event, context):
    # 파이어베이스 세팅
    cred = credentials.Certificate({
        "type": "service_account",
        "project_id": "link-1af3f",
        "private_key_id": "ac483eed3dbb7bacc1735a69499dd493de6f1e55",
        "private_key": "-----BEGIN PRIVATE KEY-----\nMIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQDl8KXCPS15uD6J\nzTE58untK6OwvRVZaXsfpZn4cuN4+LTGbfG7AbTbhbQiPsyX9NOR7oRkcqnr8qsD\nh8A7i1KRZwjwMJS/kvAdPIVpEDpn0ZcGpFccqM7dGY0Gsipf32vf4evB+uTXxon/\nqYyTTkaMr9J/uBH1nG4bexBpJuOpGMNzLplLJgc57OLVVYpapffCq8MJcdmiM4v7\nr2gVFmpN3kp11Mm6KuI0Nb42P2CUxQBEQGvTUM+cKOSpXnqs7X4XSBh9Ntju6nSs\nfw9l7CrL8+CRDOQngTX7Um2Hl+Wqk4lkhZls/2X6xLm87PAHqrGpuJRRf/bJ886x\n6pFonF9lAgMBAAECggEALWKH3SRlHvLKSTm6fyUengTwjLhth9XlivQNRXgrxNtW\nFxppTY+DKpcj3GSHznBw+Atbj1YAiwU9UveO7lHMDM4I+hukqIFwqlyhOoEM/iPk\nytdSKGJ7XjGmX813xq+bI7f8aC/EzoAuCcvl5sda7nbftfzXcqKbKwppzU9zPRM5\n4AAnLvL/YXgb8yvRiPsTgk5jGRAeAWzCwUhcTP4RQynle/I4itrhnwzXGQO7L1/N\n8fzXGy44IEUNbjDfKEVRbTr5wrtMGGDbKA+VBeGCavNPOqiAAnFIISrWy+8W2Ihi\nJol63tFzg3oTQIY7alkL98k38mpFv+SfklQttzp1OwKBgQD66ZXX9oICbelUDXPe\ndvJlAYh5MX3cKGIBagLOLu4B4L7aTyW3GFeAPtJGCg5j+Yc+1bg9IKiyJ3LiX/ni\ncwPurjhkOPdd1x4iJ1UQt1Qh1Wln2z91DS11+0ff6YKYZM8Z54Sqajio2qhzp+fH\npScvjeW7nkJvwPeDFA4KvtnlOwKBgQDqmjNLqgh6iomH96F1A65CfIvIwEoOwxPi\np9tp+Cjv7V861q/Gi8peWR+f6jGEYw5j/rrTDrxGiANYo0Fwl8oAFi5AQCZzA9Sa\nnlzOKAwrbdLaClzcwNQowx3mLLIgSUue6vUC/kwcOuevlVKADh4stMLKshuiC70q\nFSTKR3oD3wKBgGO3/cNsxtKsV/T9u7UIVOFrsI9p6flbW0fwl9jVseWxKmic2AJi\nfDQNw4fuazW0b9m7GpPArQrQvsnVFvy2dTOgrey27yiuW917AEW6dodTx6Zs7lVY\nvV6MVU5aAXsLZXuIFaOcv5PsAtKkQmuH6YDuxgTAquq7KCNCDyqaGwMNAoGAGW4d\noVYNFTtvLQ3qsoRzn0Fg5aHyZSdAQJFxd0svJNLWP8qFwz/j79Y5V1xLgc47ARvb\npIU0Y3Da7ADGVy4c92VwHgbWJCGGKjyAUtiEeTCuanQ1HLjKRqDf3NN7e4R2bgOK\nC4kFNworkxzclITzQGVXuCEWXbpoBufD1SlqUIECgYAO65u7gLGFw2CHngnysA1z\nUYPTh/EFQD0vAlRk1QCUd7mjL13vZ7BWmcJYgAEIGptkgEn4qV3GcUPqsCb6ytA7\n3bgmM6cZZcl0EV4U224LRxb948/UY54E6edEHwWk47SAprXOEB/k+TEC8K7jkb81\nUxpugOHVnuU5S2zbtli1kQ==\n-----END PRIVATE KEY-----\n",
        "client_email": "firebase-adminsdk-k462i@link-1af3f.iam.gserviceaccount.com",
        "client_id": "111694627457601479943",
        "auth_uri": "https://accounts.google.com/o/oauth2/auth",
        "token_uri": "https://oauth2.googleapis.com/token",
        "auth_provider_x509_cert_url": "https://www.googleapis.com/oauth2/v1/certs",
        "client_x509_cert_url": "https://www.googleapis.com/robot/v1/metadata/x509/firebase-adminsdk-k462i%40link-1af3f.iam.gserviceaccount.com"
    })
    firebase_admin.initialize_app(cred, {"projectId": "link-1af3f"})
    db = firestore.client()

    # 셀레니움 설정
    path = os.getcwd() + "/chromedriver"
    driver = webdriver.Chrome(path)
    driver2 = webdriver.Chrome(path)

    # 공지종류
    normalNoti = "FA1"  # 일반공지
    univNoti = "FA2"  # 학사공지
    employNoti = "FA34"  # 채용공지
    startupNoti = "FA35"  # 창업공지
    notiList = [normalNoti, univNoti, employNoti, startupNoti]  # 공지리스트

    for k in notiList:
        # 추출하고자 하는 페이지링크
        driver.get("https://www.uos.ac.kr/korNotice/list.do?list_id=" + k)

        # 첫페이지 공지 개수 파악
        titleList = driver.find_elements_by_xpath("//*[@id=\"contents\"]/ul/li")
        # subTitleList = driver.find_elements_by_xpath("//*[@id=\"contents\"]/ul/li/ul")
        type = "공백"
        if k == "FA1":
            type = "일반공지"
        if k == "FA35":
            type = "창업공지"
        if k == "FA2":
            type = "학사공지"
        if k == "FA34":
            type = "직원채용"

        # 데이터 크롤링
        if k != "FA35":
            for i in range(1, len(titleList) + 1):
                # 제목
                title = driver.find_element_by_xpath("//*[@id=\"contents\"]/ul/li[{0}]/a".format(i)).text
                if "[공지]" in title:
                    continue

                # 부서 + 날짜 + 본 횟수
                subTitle = driver.find_element_by_xpath("//*[@id=\"contents\"]/ul/li[{0}]/ul".format(i)).text
                department = subTitle.split("\n")[0]
                date = subTitle.split("\n")[1]

                # Js 텍스트(고유값+링크)
                onclick = driver.find_element_by_xpath("//*[@id=\"contents\"]/ul/li[{0}]/a".format(i)).get_attribute(
                    "onclick")
                uid = str(onclick).split("\'")[3]
                url = "https://www.uos.ac.kr/korNotice/view.do?list_id=" + k + "&seq=" + uid
                # contents > ul > li:nth-child(2) > div.txt > ul
                driver2.get(url)

                detail_content = driver2.find_element_by_xpath("//*[@id=\"view_content\"]".format(i)).text

                print(uid)
                print(title)
                print(department)
                print(int(date[:4] + date[5:7] + date[8:]))
                print(url)
                print(type)
                # print(detail_content)

                # 파이어스토어에 업로드
                docRef = db.collection("test_공지사항").document(uid)
                docRef.set({
                    "uid": uid,
                    "title": title[len(uid):],
                    "department": department,
                    "type": type,
                    "post_date": int(date[:4] + date[5:7] + date[8:]),
                    "detailurl": url,
                    "detail_content": detail_content
                })
        else:
            for i in range(1, len(titleList) + 1):
                # 제목
                title = driver.find_element_by_xpath("//*[@id=\"contents\"]/ul/li[{0}]/a".format(i)).text
                if "[공지]" in title:
                    continue

                # 부서 + 날짜 + 본 횟수
                subTitle = driver.find_element_by_xpath("//*[@id=\"contents\"]/ul/li[{0}]/ul".format(i)).text
                size = driver.find_elements_by_xpath("//*[@id=\"contents\"]/ul/li[{0}]/ul".format(i))
                department = "창업지원단"
                for m in range(0, len(size) + 1):
                    date = subTitle.split("\n")[m]
                    if len(date) > 7:
                        break
                # Js 텍스트(고유값+링크)
                onclick = driver.find_element_by_xpath("//*[@id=\"contents\"]/ul/li[{0}]/a".format(i)).get_attribute(
                    "onclick")
                uid = str(onclick).split("\'")[3]
                url = "https://www.uos.ac.kr/korNotice/view.do?list_id=" + k + "&seq=" + uid
                driver2.get(url)

                detail_content = driver2.find_element_by_xpath("//*[@id=\"view_content\"]".format(i)).text

                print(uid)
                print(type)
                print(title)
                print(department)
                print(int(date[:4] + date[5:7] + date[8:]))
                print(url)
                # print(detail_content)

                # 파이어스토어에 업로드
                docRef = db.collection("test_공지사항").document(uid)
                docRef.set({
                    "uid": uid,
                    "title": title[len(uid):],
                    "department": department,
                    "type": type,
                    "post_date": int(date[:4] + date[5:7] + date[8:]),
                    "detailurl": url,
                    "detail_content": detail_content
                })

    return "파이어스토어에 공지사항 데이터 업로드 완료!"


if __name__ == '__main__':
    lambda_handler(1, 1)
