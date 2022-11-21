pipeline {
  agent {
    node {
      label 'whnNote'
    }

  }
  stages {
    stage('static-test') {
      steps {
        powershell 'cd D:\\jenkins_workspace '
        powershell 'python static_test.py'
      }
    }

    stage('run-test') {
      steps {
        powershell 'cd D:\\jenkins_workspace'
        powershell 'python skyeye_test.py'
      }
    }

  }
}