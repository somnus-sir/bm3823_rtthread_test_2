pipeline {
  agent {
    node {
      label 'whnNote'
    }

  }
  stages {
    stage('static-test') {
      steps {
        powershell 'cd D:\\jenkins_workspace python static_test.py '
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