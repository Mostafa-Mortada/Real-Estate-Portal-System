# 🏡 Real Estate Portal System

## 📌 Overview

This C++ project is a Real Estate Portal System built using Windows Forms. It enables users to explore, list, compare, and purchase properties. Admins manage listings and users, while data persistence is handled through local file storage.

---

## 🌟 Features

### 👤 User Functionality

- Register, log in, and manage profiles
- Add and edit properties (new listings are marked as pending until approved)
- Search with advanced filters (location, price, property type, square footage, bedrooms)
- Compare up to four properties side by side
- Purchase properties using credit card and account balance

### 🛠️ Admin Capabilities

- Access the admin dashboard
- Approve or reject user-submitted properties
- Edit, delete, or highlight any property
- All users can edit any property (admin-only functionality)
- Freeze/unfreeze user accounts to restrict submissions or purchases
- Company Balance: If a user buys a property owned by the company, the payment is transferred to a shared balance accessible to all admins

---

## 🎥 Demo Video

Watch a demo of the system in action:

📺 [View the Demo Video](https://drive.google.com/file/d/1WNIpxYEBx4u7I57l7Bez7z2WAFSm2YBP/view?usp=sharing)

---

## 📸 Screenshots

Here are some key visuals of the system in action:

### 🖼️ Sign In Page
![Sign In Page](screenshots/signin_page.png)

### 🔍 User Search
![User Search](screenshots/user_search.png)

### 📊 Comparison View
![Comparison View](screenshots/comparison_view.png)

### 🛠️ Manage Requests (Admin)
![Admin Requests](screenshots/admin_manage_requests.png)

### 🔒 Moderate Users
![Moderate Users](screenshots/admin_moderate_users.png)

---

## 📃 Project Structure

```
Real_Estate_Portal_System/
├── loginPage/       → Login page related files
├── AdminForm/       → Admin dashboard and functionality
├── UserInterface/   → Forms and UI components for users
├── PropertyModule/  → Property management logic
├── data/            → File-based data storage
├── screenshots/     → Project screenshots
├── RealEstateSystem.sln
├── README.md
└── .gitignore
```

---

## 📀 Data Structures Used

- `map` – for storing user accounts
- `list` – for managing property listings
- `queue` – for search processing

---

## 👥 Team Members

- Ammar Mohamed
- Mahmoud Sherif
- Ali Yehia
- Mohamed Sadek

---

## 👩‍🏫 Course Professors

- Dr. Wedad Hussein
- Dr. Hanan Yousry

---

## 👏 Acknowledgements

We would like to express our sincere gratitude to our professors, Dr. Wedad Hussein and Dr. Hanan Yousry, for their valuable guidance and support throughout the course. Their insights greatly improved our learning experience.

