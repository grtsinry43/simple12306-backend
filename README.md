# simple12306-backend

**（应付课设）** 一个简单的12306后端C++实现，使用了drogon框架，实现了用户注册、登录、查询车次、购票、退票等功能。

## 项目结构

```
├── CMakeLists.txt
├── config.json # drogon配置文件
├── config.yaml
├── controllers
│   ├── api_order.cc # 订单相关接口
│   ├── api_order.h 
│   ├── api_tickets.cc # 车次相关接口
│   ├── api_tickets.h
│   ├── api_user.cc # 用户相关接口
│   └── api_user.h
├── dbconfig # 数据库配置文件
│   ├── Dockerfile # 数据库Dockerfile
│   ├── init_table.sql # 初始化数据库表
│   └── insert_data.sql # 插入数据
├── Dockerfile
├── filters
│   ├── LoginFilter.cc # 登录过滤器
│   ├── LoginFilter.h
│   ├── VerifyFilter.cc # 验证过滤器
│   └── VerifyFilter.h
├── main.cc # 主函数
├── models
│   ├── model.json
│   ├── Orders.cc
│   ├── Orders.h
│   ├── Tickets.cc
│   ├── Tickets.h
│   ├── Users.cc
│   └── Users.h
├── plugins
├── README.md
└── views

7 directories, 26 files

```

## 运行项目

### 1.数据库容器

```shell
cd dbconfig
docker build -t simple12306-db .
docker run -d -p 5432:5432 --name simple12306-db simple12306-db
```

### 2.项目容器、安装依赖、运行项目

```shell
docker build -t simple12306-backend .
docker run -d -p 5555:5555 --name simple12306-backend simple12306-backend
```