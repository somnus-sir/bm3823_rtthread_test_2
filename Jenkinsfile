pipeline {
  agent {
    node {
      label 'whnNote'
    }

  }
  stages {
    stage('static-test') {
      steps {
        powershell(script: 'cd D:\\jenkins_workspace', encoding: 'utf-8', label: 'whnNote')
        powershell(script: 'python static_test.py ', encoding: 'utf-8', label: 'whnNote')
      }
    }

    stage('run-test') {
      steps {
        powershell 'cd D:\\jenkins_workspace'
        powershell 'D:\\install\\SkyEye\\lib\\python35\\python.exe skyeye_test.py'
      }
    }

  }
  environment {
    python = 'D:\\install\\SkyEye\\lib\\python35\\python.exe'
  }
}