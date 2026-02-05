import requests
import yaml
import os
import sys

# --- CONFIGURATION ---
URL = "https://ctf.neocyberrange.com"
TOKEN = "ctfd_3dc002cf08caba9e12d994132a263656dacb4d801b5001f44c54d92f9331b875"
# ---------------------

headers = {
    "Authorization": f"Token {TOKEN}",
    "Content-Type": "application/json"
}

def load_config():
    if not os.path.exists("challenge.yml"):
        print("❌ Error: challenge.yml not found!")
        sys.exit(1)
    with open("challenge.yml", "r") as f:
        return yaml.safe_load(f)

def create_challenge(config):
    print(f"🚀 Creating challenge: {config['name']}...")
    endpoint = f"{URL}/api/v1/challenges"
    
    data = {
        "name": config['name'],
        "category": config['category'],
        "description": config['description'],
        "value": int(config['value']),
        "type": config['type'],
        "state": config['state']
    }

    # Handle dynamic scoring - CTFd requires initial, decay, minimum
    if config['type'] == 'dynamic':
        data['initial'] = int(config.get('initial', config['value']))
        data['decay'] = int(config.get('decay', 20))
        data['minimum'] = int(config.get('minimum', 50))

    r = requests.post(endpoint, json=data, headers=headers)
    if r.status_code == 200:
        chal_id = r.json()['data']['id']
        print(f"✅ Challenge created (ID: {chal_id})")
        return chal_id
    else:
        print(f"❌ Failed to create challenge: {r.text}")
        sys.exit(1)

def add_flags(chal_id, config):
    endpoint = f"{URL}/api/v1/flags"
    for flag in config.get('flags', []):
        if isinstance(flag, str):
            content = flag
            type_ = "static"
            data_ = ""
        else:
            content = flag['content']
            type_ = flag['type']
            data_ = flag.get('data', "")

        payload = {
            "challenge_id": chal_id,
            "content": content,
            "type": type_,
            "data": data_
        }
        r = requests.post(endpoint, json=payload, headers=headers)
        if r.status_code == 200:
            print(f"🚩 Flag added: {content}")
        else:
            print(f"⚠️ Failed to add flag: {r.text}")

def upload_files(chal_id, config):
    endpoint = f"{URL}/api/v1/files"
    # Authorization header for files must NOT have Content-Type (requests handles it)
    file_headers = {"Authorization": f"Token {TOKEN}"} 
    
    for filename in config.get('files', []):
        if not os.path.exists(filename):
            print(f"⚠️ File not found: {filename}")
            continue
            
        print(f"📂 Uploading file: {filename}...")
        with open(filename, 'rb') as f:
            files = {'file': (os.path.basename(filename), f)}
            data = {'challenge_id': chal_id, 'type': 'challenge'}
            
            r = requests.post(endpoint, files=files, data=data, headers=file_headers)
            
            if r.status_code == 200:
                print("   -> Success!")
            else:
                print(f"   -> Failed: {r.text}")

if __name__ == "__main__":
    config = load_config()
    chal_id = create_challenge(config)
    add_flags(chal_id, config)
    upload_files(chal_id, config)
    print("\n✨ Deployment Complete! ✨")
