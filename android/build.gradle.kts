plugins {
    id("com.android.application") version "8.6.0" apply false
    kotlin("android") version "1.8.0" apply false
}

allprojects {
    repositories {
        google()
        mavenCentral()
        jcenter()
    }
}

implementation("com.android.application:com.android.application.gradle.plugin:8.6.0")

android {
    compileSdkVersion 34
    defaultConfig {
        applicationId "com.vava.mapp"
        minSdkVersion 26
        targetSdkVersion 34
        versionCode 1
        versionName "1.0"

        vectorDrawables {
            useSupportLibrary = true
        }
    }
    buildTypes {
        release {
            minifyEnabled false
            proguardFiles getDefaultProguardFile('proguard-android-optimize.txt'), 'proguard-rules.pro'
        }
    }
    compileOptions {
        sourceCompatibility JavaVersion.VERSION_17
        targetCompatibility JavaVersion.VERSION_17
    }
    kotlinOptions {
        jvmTarget = '17.0.12'
    }
}

dependencies {
    implementation "androidx.core:core-ktx:1.8.0"
    implementation "androidx.appcompat:appcompat:1.5.1"
    implementation "androidx.compose.material3:material3:1.0.1"
}