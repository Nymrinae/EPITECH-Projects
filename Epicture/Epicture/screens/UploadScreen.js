import * as React from 'react';
import { 
  Image, 
  StyleSheet,
  StatusBar,
  Text,
  TouchableOpacity,
  View
} from 'react-native';
import * as ImagePicker from 'expo-image-picker';
import * as ExpoFS from 'expo-file-system'
import * as MediaLibrary from 'expo-media-library'
import * as Permissions from 'expo-permissions';

import Constants from 'expo-constants';
import { uploadImage } from '../api/Image'

export default class UploadScreen extends React.Component {
  constructor(props) {
    super(props)

    this.state = {
      image: null,
    }
  }

  componentDidMount() {
    this.getPermissionAsync();
  }

  getPermissionAsync = async () => {
    if (Constants.platform.ios) {
      const { status } = await Permissions.askAsync(Permissions.CAMERA_ROLL);
      if (status !== 'granted') {
        alert('Sorry, we need camera roll permissions to make this work!');
      }
    }
  }

  pickImage = async () => {
    let result = await ImagePicker.launchImageLibraryAsync({
      mediaTypes: ImagePicker.MediaTypeOptions.All,
      allowsEditing: true,
      aspect: [4, 3],
    });

    if (!result.cancelled) {
      this.setState({ image: result.uri });
    }
  }

  launchCamera = async () => {
    let result = await ImagePicker.launchCameraAsync({
      mediaTypes: ImagePicker.MediaTypeOptions.All,
      allowsEditing: true,
      aspect: [4, 3],
    });

    if (!result.cancelled) {
      this.setState({ image: result.uri });
    }
  }

  uploadToImgur = async () => {
    let { image } = this.state
    let base64Image = await ExpoFS.getInfoAsync(image)
    let uri = base64Image.uri
    let data = new FormData()
    let file = await MediaLibrary.createAssetAsync(uri)

    data.append('image', {
      uri: file.uri,
      name: 'epicturetest',
      title: 'Epicture Test',
      description: 'Random image for Epicture',
      type: 'image/png'
    })

    await uploadImage(data);
  }

  renderImage() {
    if (this.state.image) {
      return (<Image source={{ uri: this.state.image }} style={styles.image} />)
    }
  }

  render() {
    let { image } = this.state;

    return (
      <View style={styles.container}>
        <StatusBar translucent barStyle="dark-content"/>
        <Text style={styles.presentationText}> Pick Images from Camera or Gallery</Text>
        { this.renderImage() }
        <TouchableOpacity
          style={styles.input}
          onPress={this.pickImage}
        >
          <Text> Pick an image from your Gallery !</Text>
        </TouchableOpacity>
        <TouchableOpacity
          style={styles.input2}
          onPress={this.launchCamera}
        >
          <Text> Take a photo with your camera </Text>
        </TouchableOpacity>
        <TouchableOpacity
          style={styles.input}
          onPress={this.uploadToImgur}
        >
          <Text> Upload to imgur ! </Text>
        </TouchableOpacity>
      </View>
    )
  }
}

UploadScreen.navigationOptions = {
  title: 'Upload something !'
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center', 
    justifyContent: 'center',
    marginBottom: 50
  },
  presentationText: {
    textAlign: 'center',
    fontSize: 20,
    paddingBottom: 20
  },
  input: {
    height: 60,
    width: 300,
    alignItems: 'center',
    backgroundColor: '#ededed',
    borderRadius: 4,
    padding: 20,
    marginBottom: 10
  },
  input2: {
    height: 60,
    width: 300,
    alignItems: 'center',
    backgroundColor: '#ededed',
    borderRadius: 4,
    padding: 20,
    marginBottom: 100
  },
  image: {
    width: 200,
    height: 200,
    borderColor: 'black',
    borderWidth: 2,
    marginBottom: 50
  }
})